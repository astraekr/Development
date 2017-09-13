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



folderName = 'pics'
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
    photoList = [os.path.basename(f) for f in glob.glob(os.path.join(parent_dir, '*.png'))]
    photoList.sort()

    count = 0
    #get averages and arrange them into an array
    for name in photoList:
        print name
        image = cv2.imread(folderName+'/'+name, 0)
        #format: gray[y1:y2, x1:x2]     
        region = image[55:119, 129:203]
        #region = image[129:203, 55:119]
        #get average
        #avgRowColour = numpy.average(region, axis = 0)
        #avg = numpy.average(avgRowColour, axis = 0)
        
        avg = numpy.mean(region)
        
        print('average intensity = ' + str(avg))  
        averages.append(avg)
        #count = count +1
        #print count
        
    print(len(averages))
    tl = numpy.arange(1,len(averages)+1)

    forecastPlot = plt.plot(tl, averages, 'b-', label='Averages')
    #resultPlot = plt.plot(tl,trimmedAveragesExtend, 'r-',label='Actual results')
    
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

