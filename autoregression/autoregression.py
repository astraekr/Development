import numpy as np
import pandas
import statsmodels.api as sm
from statsmodels.tsa.api import VAR, DynamicVAR
from pandas import Series
from matplotlib import pyplot
from statsmodels.tsa.ar_model import AR
import sklearn.metrics
import glob, os
import csv
import cv2
import numpy
import matplotlib.pyplot as plt
import datetime
from datetime import datetime
import time



#INFO http://www.statsmodels.org/stable/vector_ar.html#var

#also normal autoregression http://machinelearningmastery.com/autoregression-models-time-series-forecasting-python/ 

#OUTPUT: Red line is the actual data
#OUTPUT: Blue line is the predicted data

folderName = '2017-05-22 15:39:35.767093'
csvName = '2017-05-22 15:39:35.767093_358.csv'

#NOTE why is one set of values one time interval after the other?

def main():

    predictionLength = 10
    #this is the number of points in the dataset
    #AKA the point at which we start predicting the data
    #first try was 359
    numDataPoints = 359
    totalDataPoints =715
    lagLength = 60
    times = []
    timesSecs = []
    results = []
    averages = []
    temps = []
    UVs = []
    positions = []
    t = []
    forecastAverage = np.ndarray(shape=(numDataPoints+predictionLength,1))
    
    newData = np.ndarray(shape =(0,4), dtype=float)
    newArray = np.ndarray(shape =(0,4), dtype=float)
    t = datetime(1900, 1, 1, 15, 40)
        
    parent_dir = folderName
    photoList = [os.path.basename(f) for f in glob.glob(os.path.join(parent_dir, '*.jpg'))]
    photoList.sort()

    count = 0
    #get averages and arrange them into an array
    for name in photoList:
        image = cv2.imread(folderName+'/'+name, 0)
        #pixels: 23,8  49,8  49,32  23,32
        #format: gray[y1:y2, x1:x2]     
        region = image[19:44, 27:56]
        #get average
        avgRowColour = numpy.average(region, axis = 0)
        avg = numpy.average(avgRowColour, axis = 0)
        #print('average intensity = ' + str(avg))  
        averages.append(avg*5)
        #count = count +1
        #print count
      

    #trim average pixel values so we only have the ones we care about for the prediction        
    stuffToDelete = np.arange(numDataPoints+1, totalDataPoints+1)    
    trimmedAverages = np.delete(averages, stuffToDelete, axis=0)      
    fullAverages = averages
    averages = trimmedAverages
    
    #trim average pixel values, leaving 'predictionLength + numDataPoints' extra values for comparing with the prediction
    
    #stuffToDelete = np.arange(numDataPoints+predictionLength+1, totalDataPoints+1) 
    stuffToDelete = np.arange(numDataPoints+predictionLength, totalDataPoints+1)   
    trimmedAveragesExtend = np.delete(fullAverages, stuffToDelete, axis=0)      
    
    #open csv file, get data ready
    
        
    #attempt at getting the data from the csv file using numpy
    with open(folderName+'/'+csvName, 'rb') as csvfile:

        dataReader = csv.reader(csvfile, delimiter=',',quotechar='|')

        count = 0
        for row in dataReader:
            #convert time strings to datetime objects
            times.append(datetime.strptime(row[0], '%H:%M:%S.%f'))
            
            timesSecs.append((times[count]-t).total_seconds())
            #times.append(float(row[0]))
            #15:39:35.767093
            #times.append.datetime.strptime(row[0], '%H:%M:%S.%f')
            temps.append(float(row[1]))
            positions.append(float(row[2])) 
            count = count + 1
        
                       
        for i in range(len(timesSecs)):
            insertArray = (timesSecs[i],temps[i],positions[i],averages[i])
            newArray = np.append(newArray,[insertArray], axis=0)
           
       
        model = VAR(newArray) 
        results = model.fit(lagLength)
        lag_order = results.k_ar
        
        #forecast takes parameters:
        #forecast(y, coefs, trend_coefs, steps, exog=None)
        forecast = results.forecast(newArray[-lag_order:], predictionLength)
        #add the new, forecast results to the actual data
        forecastResults = np.append(newArray, forecast, axis=0)
        
        #get the forecast average pixel value from the multi-d array
        for i in range(len(forecastResults)):
            forecastAverage[i] = forecastResults[i,3]
        

        tl  = numpy.arange(1,numDataPoints+predictionLength+1)
        
        print forecastAverage[len(forecastAverage)-20:len(forecastAverage)]
        
        print trimmedAveragesExtend[len(trimmedAveragesExtend)-20:len(trimmedAveragesExtend)]
        
        print len(tl),len(forecastAverage),len(trimmedAveragesExtend)
        
        forecastPlot = plt.plot(tl, forecastAverage, 'b-', label='Forecast')
        resultPlot = plt.plot(tl,trimmedAveragesExtend, 'r-',label='Actual results')
        
        plt.ylabel('Average pixel value (unitless)')
        plt.xlabel('Data point')
        
        legend = plt.legend(loc='lower left', shadow=True)
        frame = legend.get_frame()
        frame.set_facecolor('0.90')
        # Set the fontsize
        for label in legend.get_texts():
            label.set_fontsize('large')

        for label in legend.get_lines():
            label.set_linewidth(1.5)  # the legend line width
        
        #plt.plot(tl, forecastAverage, 'b-', trimmedAveragesExtend, 'r-')
        plt.show()
        
        
        #print(results.summary())
        #results.plot()
        #results.plot_forecast(20)
        
        #2nd data
        #t  = numpy.arange(1,716)
        #plt.plot(t, temps,'b-', t, positions, 'r-', t, averages, 'b-', forecast, 'r-')
        #plt.show()        
        

if __name__ == "__main__": main()
