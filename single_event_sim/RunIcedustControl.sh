source /scratchfs/bes/zkzhang/COMET/Simulation/Single_event/input/setup.sh

# Tell us the job has started
echo "Start time:" >> /scratchfs/bes/zkzhang/COMET/Simulation/Single_event/log/timers
date +"%s" >> /scratchfs/bes/zkzhang/COMET/Simulation/Single_event/log/timers

# Run the job
{ export OUTPUT_DIR=/sharefs/bes/zkzhang/Graduation/Tracking/MCTracking/sim/output/
  export SH_RUN_NUMBER=1
  export SH_SUBRUN=0
  export SH_RANDOM_SEED=104971
  export SH_NUM_EVENTS=1
  export SH_VERSION_NUMBER=0
  /workfs2/bes/zkzhang/ICEDUST/ICEDUST_install/IcedustControl/app/RunIcedustControl -c /scratchfs/bes/zkzhang/COMET/Simulation/Single_event/input/CyDet_signal.cfg
} || {
  echo "Signal Job Failed"
  echo "Fail time:" >> /scratchfs/bes/zkzhang/COMET/Simulation/Single_event/log/timers
  date +"%s" >> /scratchfs/bes/zkzhang/COMET/Simulation/Single_event/log/timers
}

# Tell us the job has stopped
echo "Stop time:" >> /scratchfs/bes/zkzhang/COMET/Simulation/Single_event/log/timers
date +"%s" >> /scratchfs/bes/zkzhang/COMET/Simulation/Single_event/log/timers

