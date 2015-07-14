#import word
import connectedComponentsComputation
import numpy

#w = word.Word(b"foo")

#print(w.reverse())

v = numpy.array([
    [0.,0.,0.],
    [1.,0.,0.],
    [0.,1.,0.],
    [0.,0.,1.],
    [10.,10.,10.],
    [11.,10.,10.],
    [10.,11.,10.],
    [10.,10.,11.]
    ], dtype = numpy.float32)

f = numpy.array([        
    [4,6,7], 
    [0,1,2],
    [5,6,7],
    [0,2,3],
    [0,1,3],
    [1,2,3],
    [4,5,7],
    [4,5,6] 
    ], dtype = numpy.int32)

c = connectedComponentsComputation.ConnectedComponentsComputation()
# c.getComponents(b'\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', 4, b'\0\0\x01\0\x02\0\x01\0\x02\0\x03\0\0\0\x01\0\x03\0\0\0\x02\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0', 4)
c.getComponents(v[0:8].tostring(), 8, f[0:8].tostring(), 8);