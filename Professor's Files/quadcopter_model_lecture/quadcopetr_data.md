Vehicle.Airframe: 
 mass: 0.063000000000000
     inertia: Ixx = 5.828570000000000e-05, Iyy = 7.169140000000000e-05, Izz =  1.000000000000000e-04
           d: 0.062400000000000
          xy: 0.044123463146041
           h: -0.015876000000000
         Cdx: 0
         Cdy: 0
    diameter: 0.010000000000000

Vehicle.Rotor
            blades: 2
            radius: 0.033000000000000
             chord: 0.008000000000000
    flappingOffset: 0
         bladeMass: 3.750000000000000e-04
      bladeInertia: 1.020937500000000e-07
           hubMass: 0
        hubInertia: 0
           inertia: 1.020937500000000e-07
                Ct: 0.010700000000000
                Cq: 7.826375278505369e-04
          solidity: 0.154332066028505
            theta0: 0.254818070791172
          thetaTip: 0.118682389135614
            theta1: -0.136135681655558
           theta34: 0.152716309549504
                 a: 5.500000000000000
              area: 0.003421194399759
              lock: 0.605147136000000
                 b: 4.719990366910910e-08
                 k: 1.139283855549884e-10
    w2ToThrustGain: 4.719990366910910e-08

Vehicle.Motor
                maxLimit: 500
                minLimit: 10
         commandToW2Gain: 1.384080000000000e+04
    thrustToMotorCommand: 1.530726830648920e+03
