#import word
#import outputComponent
import connectedComponentsComputation
import numpy
import sip 

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
c.compute(v[0:8].tostring(), 8, f[0:8].tostring(), 8);

cc = c.getComponent(0);

print(type(cc.verts))
print(cc.n_verts)
print(cc.verts)

# v0 = numpy.fromiter(cc.verts , dtype=numpy.float32, count = cc.n_verts)
#print(v0)

re = c.re().asarray(cc.n_verts)
#print(dir(re))
print("forward")
print(re[0])
print(re[1])
print(re[2])
print(re[3])
print("backward")
print(re[0])
print(re[-1])
print(re[-2])
print(re[-3])
print("sdg")
print(re.__getitem__(0))

print(sip.ispyowned(cc)) # True







