### Describe the effect each of the P, I, D components had in your implementation.
- P : if I left the weight for P too low, the car wouldn't turn fast enough to handle some of the sharper corners. This makes sense, as P has the most obvious impact on turning the car.
- I : This seemed not that important, and in general a small weight would do. This makes sense as it is mainly to handle systematic errors.
- D : Important to tune, it would control how much the car oscillated. It is difficult to remove this entirely, and I notice that the car still has a slight oscillation behavior whenever it exits a turn.

### Describe how the final hyperparameters were chosen.

- First I used the twiddle implementation, starting with `{0.225, 0.004, 4.0}` as my parameters, and dp as 1/10th of these values
- However, I did notice that training of the twiddle algorithm was a little slow. I also tried using 1/5th of the values as dp, but the D component quickly deteriorated
- I picked one of the middle values from training `{0.126, 0.002, 2.5}`, and then manually tuned it afterwards, resulting in the final values of `{0.136,0.00032,1.4}`


## Review/ Feedback

Below are some of the useful links

- https://www.thorlabs.com/tutorials.cfm?tabID=5dfca308-d07e-46c9-baa0-4defc5c40c3e
- https://udacity-reviews-uploads.s3.amazonaws.com/_attachments/41330/1493863065/pid_control_document.pdf under section on tuning the constant terms
- https://robotics.stackexchange.com/questions/167/what-are-good-strategies-for-tuning-pid-loops
- https://medium.com/@techreigns/pid-controller-for-autonomous-vehicles-ed2c2ccbbb86
- https://hackernoon.com/a-conceptual-breakdown-of-pid-controllers-9fa072a140a5
- https://www.researchgate.net/post/Automating_tuning_of_PID_Controllers
- https://www.aiche.org/resources/publications/cep/2016/february/pid-explained-process-engineers-part-2-tuning-coefficients
- https://en.wikipedia.org/wiki/PID_controller
- https://docs.google.com/viewer?url=http%3A%2F%2Fportal.research.lu.se%2Fws%2Ffiles%2F33100749%2FThesisJosefinBerner.pdf
- https://docs.google.com/viewer?url=https%3A%2F%2Fpdfs.semanticscholar.org%2F4bdd%2F25ea2d463ed7626eb37d18be1687b3a4391e.pdf
- https://medium.com/@cacheop/pid-control-for-self-driving-1128b42ab2dd

