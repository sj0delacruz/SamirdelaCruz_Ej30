
#ani = FuncAnimation(fig, update, frames=range(num_x), init_func=init, blit=True)
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

dat=np.loadtxt("dat_ec5.dat")
num_x=dat.shape[1]
num_t=dat.shape[0]

xdata, ydata = np.linspace(0,1,num_x), []
fig, ax = plt.subplots()
ax.grid()
ln, = plt.plot(xdata, dat[0])

def init():  # only required for blitting to give a clean slate.
    ax.set_xlim(0, 1)
    ax.set_ylim(-0.5, 0.5)
    ax.set_xlabel("Posicion [metros]")
    ax.set_ylabel("U")
    return ln,


def animate(i):
    ln.set_ydata(dat[i])
    ax.set_title("Tiempo: "+ str("{0:.2f}".format(2*i/(num_t-1)))+ " segundos")
    return ln,


ani = animation.FuncAnimation(
    fig, animate, init_func=init, interval=100,frames=range(num_t), blit=True,repeat=True)

# To save the animation, use e.g.
#
ani.save("sol_ec5.gif",fps=10)
#
# or
#
#from matplotlib.animation import FFMpegWriter
# writer = FFMpegWriter(fps=15, metadata=dict(artist='Me'), bitrate=1800)
# ani.save("movie.mp4", writer=writer)

