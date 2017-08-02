import glob, os
import csv
import cv2
import numpy
import matplotlib.pyplot as plt


folderName = '2017-05-22 15:39:35.767093'
csvName = '2017-05-22 15:39:35.767093.csv'


def main():

    #get pic names
    results = []
    averages = []
    temps = []
    UVs = []
    positions = []
    t = []
    
    
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
    
    #open csv file, get data ready
    with open(folderName+'/'+csvName, 'rb') as csvfile:
        dataReader = csv.reader(csvfile, delimiter=',')
        for row in dataReader:
            print row
            print('in the loop')
            temps.append(float(row[1]))
            #UVs.append(float(row[2]))
            positions.append(float(row[2]))
            count = count +1
            print count
        
        for row in dataReader:
            print(','.join(row))
            
        #count = 0
        

            
        #dataReader.head()
        
        #2nd data
        t  = numpy.arange(1,716)
        #most recent data number
        #t  = numpy.arange(1,749)
                
        plt.plot(t, temps,'bo', t, positions, 'r+', t, averages, 'b+')
        plt.show()
            
              
            
    #REGRESSION
    #FEATURES: ambient temperature, knob position, uv level, time since knob position change
    #RESPONSE: average pixel value

    
if __name__ == "__main__": main()
