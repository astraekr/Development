        
        
        #for row in times:
            #timesSecs.append((row-t).total_seconds())
            
                #count = 0
        
        #this applies only to the data in file 2017-05-22 15:39:35.767093.csv
        #get the time data to be in only seconds from the start of the experiment
        #for row in dataReader:
            #print('in first dataReader for loop')
            #convert time strings to datetime objects
            #times.append(datetime.strptime(row[0], '%H:%M:%S.%f'))
            
        #dt = np.dtype([('datetime', [('date', int), ('time', int)]),('Temp', float)], [('UV', float)], [('Knob', int)]) 
        #dt = np.dtype([('time', float)], [('Temp', float)], [('UV', float)], [('Knob', int)])
        #newData = np.fromfile(csvfile, dtype=dt)


"""
series = Series.from_csv('daily-minimum-temperatures-in-me.csv', header=0)

# split dataset
X = series.values
train, test = X[1:len(X)-7], X[len(X)-7:]
# train autoregression
model = AR(train)
model_fit = model.fit()
print('Lag: %s' % model_fit.k_ar)
print('Coefficients: %s' % model_fit.params)
# make predictions
predictions = model_fit.predict(start=len(train), end=len(train)+len(test)-1, dynamic=False)
for i in range(len(predictions)):
	print('predicted=%f, expected=%f' % (predictions[i], test[i]))
error = sklearn.metrics.mean_squared_error(test, predictions)
print('Test MSE: %.3f' % error)
# plot results
pyplot.plot(test)
pyplot.plot(predictions, color='red')
pyplot.show()"""
