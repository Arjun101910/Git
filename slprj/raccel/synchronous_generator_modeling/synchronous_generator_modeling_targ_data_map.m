  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 119;
      section.data(119)  = dumData; %prealloc
      
	  ;% rtP.HydraulicTurbineandGovernor_dref
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.HydraulicTurbineandGovernor_po
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.units1_Gain
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.Lmq_sat_Y0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.Laq_Y0
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.uLl_q_Gain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.u2_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtP.Integrator_IC
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% rtP.uDLookupTable_tableData
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% rtP.uDLookupTable_bp01Data
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 21;
	
	  ;% rtP.Constant1_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 31;
	
	  ;% rtP.Lmq_Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 32;
	
	  ;% rtP.uTT1e6s_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 33;
	
	  ;% rtP.Linv_Y0
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 34;
	
	  ;% rtP.RLinv_Y0
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 35;
	
	  ;% rtP.Lmqd_Y0
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 36;
	
	  ;% rtP.Laqd_Y0
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 37;
	
	  ;% rtP.uLl_d_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 38;
	
	  ;% rtP.u1_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 41;
	
	  ;% rtP.Integrator_IC_okxqdvaqge
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 43;
	
	  ;% rtP.uDLookupTable_tableData_oh1wox4m40
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 44;
	
	  ;% rtP.uDLookupTable_bp01Data_i3bi2vd4wx
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 54;
	
	  ;% rtP.Constant1_Value_j0subfzquq
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 64;
	
	  ;% rtP.Lmd_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 65;
	
	  ;% rtP.uTT1e6s_Gain_lygg4vbdad
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 66;
	
	  ;% rtP.u1_Value_g2cyrwvzkh
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 67;
	
	  ;% rtP.u1_Value_evk3gg0wa2
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 92;
	
	  ;% rtP.u3_Value
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 117;
	
	  ;% rtP.u5_Value
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 118;
	
	  ;% rtP.u2_Value_dgzm2q1ls3
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 143;
	
	  ;% rtP.Rotorangledtheta_IC
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 144;
	
	  ;% rtP.web2_Gain
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 145;
	
	  ;% rtP.Integrator_IC_ae1cznrs4o
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 146;
	
	  ;% rtP.Constant1_Value_fc0guqcyc4
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 151;
	
	  ;% rtP.Constant3_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 152;
	
	  ;% rtP.Constant4_Value
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 153;
	
	  ;% rtP.Switch_Threshold
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 178;
	
	  ;% rtP.changeIqIdcurrentsigns_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 179;
	
	  ;% rtP.ib_Gain
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 184;
	
	  ;% rtP.StateSpace_P1_Size
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 185;
	
	  ;% rtP.StateSpace_P1
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 187;
	
	  ;% rtP.StateSpace_P2_Size
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 195;
	
	  ;% rtP.StateSpace_P2
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 197;
	
	  ;% rtP.StateSpace_P3_Size
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 201;
	
	  ;% rtP.StateSpace_P4_Size
	  section.data(45).logicalSrcIdx = 45;
	  section.data(45).dtTransOffset = 203;
	
	  ;% rtP.StateSpace_P4
	  section.data(46).logicalSrcIdx = 46;
	  section.data(46).dtTransOffset = 205;
	
	  ;% rtP.nomspeed_Value
	  section.data(47).logicalSrcIdx = 47;
	  section.data(47).dtTransOffset = 361;
	
	  ;% rtP.Rotorspeeddeviationdw_IC
	  section.data(48).logicalSrcIdx = 48;
	  section.data(48).dtTransOffset = 362;
	
	  ;% rtP.units_Gain
	  section.data(49).logicalSrcIdx = 49;
	  section.data(49).dtTransOffset = 363;
	
	  ;% rtP.Constant_Value
	  section.data(50).logicalSrcIdx = 50;
	  section.data(50).dtTransOffset = 364;
	
	  ;% rtP.Constant1_Value_c5r2ow4pnn
	  section.data(51).logicalSrcIdx = 51;
	  section.data(51).dtTransOffset = 365;
	
	  ;% rtP.StateSpace_A
	  section.data(52).logicalSrcIdx = 52;
	  section.data(52).dtTransOffset = 366;
	
	  ;% rtP.StateSpace_B
	  section.data(53).logicalSrcIdx = 53;
	  section.data(53).dtTransOffset = 367;
	
	  ;% rtP.StateSpace_C
	  section.data(54).logicalSrcIdx = 54;
	  section.data(54).dtTransOffset = 368;
	
	  ;% rtP.StateSpace_InitialCondition
	  section.data(55).logicalSrcIdx = 55;
	  section.data(55).dtTransOffset = 369;
	
	  ;% rtP.Constant1_Value_dxffpau3tt
	  section.data(56).logicalSrcIdx = 56;
	  section.data(56).dtTransOffset = 370;
	
	  ;% rtP.StateSpace_A_gvjvm0zida
	  section.data(57).logicalSrcIdx = 57;
	  section.data(57).dtTransOffset = 371;
	
	  ;% rtP.StateSpace_B_cw5oh3slxt
	  section.data(58).logicalSrcIdx = 58;
	  section.data(58).dtTransOffset = 372;
	
	  ;% rtP.StateSpace_C_brkogrmwzx
	  section.data(59).logicalSrcIdx = 59;
	  section.data(59).dtTransOffset = 373;
	
	  ;% rtP.StateSpace_InitialCondition_fevmgmfoek
	  section.data(60).logicalSrcIdx = 60;
	  section.data(60).dtTransOffset = 374;
	
	  ;% rtP.Vfdmax1_Gain
	  section.data(61).logicalSrcIdx = 61;
	  section.data(61).dtTransOffset = 375;
	
	  ;% rtP.Constant_Value_cangz0hlbt
	  section.data(62).logicalSrcIdx = 62;
	  section.data(62).dtTransOffset = 376;
	
	  ;% rtP.Constant3_Value_oy0hsbqr4o
	  section.data(63).logicalSrcIdx = 63;
	  section.data(63).dtTransOffset = 377;
	
	  ;% rtP.Vfdmax_Gain
	  section.data(64).logicalSrcIdx = 64;
	  section.data(64).dtTransOffset = 378;
	
	  ;% rtP.StateSpace_D
	  section.data(65).logicalSrcIdx = 65;
	  section.data(65).dtTransOffset = 379;
	
	  ;% rtP.StateSpace_A_jh2uawflmi
	  section.data(66).logicalSrcIdx = 66;
	  section.data(66).dtTransOffset = 380;
	
	  ;% rtP.StateSpace_B_mmoy0u0fuw
	  section.data(67).logicalSrcIdx = 67;
	  section.data(67).dtTransOffset = 381;
	
	  ;% rtP.StateSpace_C_manifxflg5
	  section.data(68).logicalSrcIdx = 68;
	  section.data(68).dtTransOffset = 382;
	
	  ;% rtP.StateSpace_D_h4wd5niec1
	  section.data(69).logicalSrcIdx = 69;
	  section.data(69).dtTransOffset = 383;
	
	  ;% rtP.StateSpace_InitialCondition_oqtdddz2en
	  section.data(70).logicalSrcIdx = 70;
	  section.data(70).dtTransOffset = 384;
	
	  ;% rtP.Vf0ka_Value
	  section.data(71).logicalSrcIdx = 71;
	  section.data(71).dtTransOffset = 385;
	
	  ;% rtP.StateSpace_D_csfvldwlau
	  section.data(72).logicalSrcIdx = 72;
	  section.data(72).dtTransOffset = 386;
	
	  ;% rtP.Constant2_Value
	  section.data(73).logicalSrcIdx = 73;
	  section.data(73).dtTransOffset = 387;
	
	  ;% rtP.uLl_q_Gain_awlrmeuumw
	  section.data(74).logicalSrcIdx = 74;
	  section.data(74).dtTransOffset = 388;
	
	  ;% rtP.Constant8_Value
	  section.data(75).logicalSrcIdx = 75;
	  section.data(75).dtTransOffset = 390;
	
	  ;% rtP.Laqd_nosat_Value
	  section.data(76).logicalSrcIdx = 76;
	  section.data(76).dtTransOffset = 391;
	
	  ;% rtP.Switch3_Threshold
	  section.data(77).logicalSrcIdx = 77;
	  section.data(77).dtTransOffset = 393;
	
	  ;% rtP.uLl_d_Gain_jijxqv5vxr
	  section.data(78).logicalSrcIdx = 78;
	  section.data(78).dtTransOffset = 394;
	
	  ;% rtP.u_Vb_Gain
	  section.data(79).logicalSrcIdx = 79;
	  section.data(79).dtTransOffset = 397;
	
	  ;% rtP.Constant5_Value
	  section.data(80).logicalSrcIdx = 80;
	  section.data(80).dtTransOffset = 398;
	
	  ;% rtP.Lmqd_nosat_Value
	  section.data(81).logicalSrcIdx = 81;
	  section.data(81).dtTransOffset = 399;
	
	  ;% rtP.Switch2_Threshold
	  section.data(82).logicalSrcIdx = 82;
	  section.data(82).dtTransOffset = 401;
	
	  ;% rtP.Gain_Gain
	  section.data(83).logicalSrcIdx = 83;
	  section.data(83).dtTransOffset = 402;
	
	  ;% rtP.Gain_Gain_acjk3icicb
	  section.data(84).logicalSrcIdx = 84;
	  section.data(84).dtTransOffset = 403;
	
	  ;% rtP.Gain1_Gain
	  section.data(85).logicalSrcIdx = 85;
	  section.data(85).dtTransOffset = 404;
	
	  ;% rtP.outputformatting_Gain
	  section.data(86).logicalSrcIdx = 86;
	  section.data(86).dtTransOffset = 405;
	
	  ;% rtP.Derivative_A
	  section.data(87).logicalSrcIdx = 87;
	  section.data(87).dtTransOffset = 423;
	
	  ;% rtP.Derivative_C
	  section.data(88).logicalSrcIdx = 88;
	  section.data(88).dtTransOffset = 424;
	
	  ;% rtP.position_IC
	  section.data(89).logicalSrcIdx = 89;
	  section.data(89).dtTransOffset = 425;
	
	  ;% rtP.position_UpperSat
	  section.data(90).logicalSrcIdx = 90;
	  section.data(90).dtTransOffset = 426;
	
	  ;% rtP.position_LowerSat
	  section.data(91).logicalSrcIdx = 91;
	  section.data(91).dtTransOffset = 427;
	
	  ;% rtP.u1_Gain
	  section.data(92).logicalSrcIdx = 92;
	  section.data(92).dtTransOffset = 428;
	
	  ;% rtP.Switch_Threshold_b2t0vmw2we
	  section.data(93).logicalSrcIdx = 93;
	  section.data(93).dtTransOffset = 430;
	
	  ;% rtP.permanentdroop_Gain
	  section.data(94).logicalSrcIdx = 94;
	  section.data(94).dtTransOffset = 431;
	
	  ;% rtP.Integral_Gain
	  section.data(95).logicalSrcIdx = 95;
	  section.data(95).dtTransOffset = 432;
	
	  ;% rtP.Integrator1_IC
	  section.data(96).logicalSrcIdx = 96;
	  section.data(96).dtTransOffset = 433;
	
	  ;% rtP.Proportional_Gain
	  section.data(97).logicalSrcIdx = 97;
	  section.data(97).dtTransOffset = 434;
	
	  ;% rtP.servomotor_A
	  section.data(98).logicalSrcIdx = 98;
	  section.data(98).dtTransOffset = 435;
	
	  ;% rtP.servomotor_C
	  section.data(99).logicalSrcIdx = 99;
	  section.data(99).dtTransOffset = 436;
	
	  ;% rtP.speedlimit_UpperSat
	  section.data(100).logicalSrcIdx = 100;
	  section.data(100).dtTransOffset = 437;
	
	  ;% rtP.speedlimit_LowerSat
	  section.data(101).logicalSrcIdx = 101;
	  section.data(101).dtTransOffset = 438;
	
	  ;% rtP.Constant_Value_f4yyiavgsx
	  section.data(102).logicalSrcIdx = 102;
	  section.data(102).dtTransOffset = 439;
	
	  ;% rtP.turbinegain_Gain
	  section.data(103).logicalSrcIdx = 103;
	  section.data(103).dtTransOffset = 440;
	
	  ;% rtP.beta_Gain
	  section.data(104).logicalSrcIdx = 104;
	  section.data(104).dtTransOffset = 441;
	
	  ;% rtP.Gain2_Gain
	  section.data(105).logicalSrcIdx = 105;
	  section.data(105).dtTransOffset = 442;
	
	  ;% rtP.N_Gain
	  section.data(106).logicalSrcIdx = 106;
	  section.data(106).dtTransOffset = 443;
	
	  ;% rtP.Constant2_Value_ewacipohvd
	  section.data(107).logicalSrcIdx = 107;
	  section.data(107).dtTransOffset = 444;
	
	  ;% rtP.Constant6_Value
	  section.data(108).logicalSrcIdx = 108;
	  section.data(108).dtTransOffset = 445;
	
	  ;% rtP.Gain1_Gain_fsvmmhhhj3
	  section.data(109).logicalSrcIdx = 109;
	  section.data(109).dtTransOffset = 470;
	
	  ;% rtP.u1_Value_c5nzdrro12
	  section.data(110).logicalSrcIdx = 110;
	  section.data(110).dtTransOffset = 471;
	
	  ;% rtP.Switch1_Threshold
	  section.data(111).logicalSrcIdx = 111;
	  section.data(111).dtTransOffset = 496;
	
	  ;% rtP.Vkd0Vkq10Vkq20_Value
	  section.data(112).logicalSrcIdx = 112;
	  section.data(112).dtTransOffset = 497;
	
	  ;% rtP.wbase_Gain
	  section.data(113).logicalSrcIdx = 113;
	  section.data(113).dtTransOffset = 499;
	
	  ;% rtP.u_Pb_Gain
	  section.data(114).logicalSrcIdx = 114;
	  section.data(114).dtTransOffset = 500;
	
	  ;% rtP.F1_Gain
	  section.data(115).logicalSrcIdx = 115;
	  section.data(115).dtTransOffset = 501;
	
	  ;% rtP.u_2H_Gain
	  section.data(116).logicalSrcIdx = 116;
	  section.data(116).dtTransOffset = 502;
	
	  ;% rtP.theta_IC
	  section.data(117).logicalSrcIdx = 117;
	  section.data(117).dtTransOffset = 503;
	
	  ;% rtP.web1_Gain
	  section.data(118).logicalSrcIdx = 118;
	  section.data(118).dtTransOffset = 504;
	
	  ;% rtP.web3_Gain
	  section.data(119).logicalSrcIdx = 119;
	  section.data(119).dtTransOffset = 505;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtP.Constant1_Value_ottz5lhlaz
	  section.data(1).logicalSrcIdx = 120;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Constant2_Value_ihmgbjdayf
	  section.data(2).logicalSrcIdx = 121;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.Constant3_Value_c5mzzegack
	  section.data(3).logicalSrcIdx = 122;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.Constant1_Value_ai2pb13mhx
	  section.data(4).logicalSrcIdx = 123;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 120;
      section.data(120)  = dumData; %prealloc
      
	  ;% rtB.kr1l0f0n1y
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.f0tfi2aikm
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.hcevlizke0
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.aevoxybjly
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.ju1jshvwhr
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% rtB.hgnzqmdjot
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 33;
	
	  ;% rtB.plsr00p5pu
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 38;
	
	  ;% rtB.omelmho425
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 43;
	
	  ;% rtB.ieios15ick
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 44;
	
	  ;% rtB.hrt2qdvvir
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 47;
	
	  ;% rtB.hodx3vvveu
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 49;
	
	  ;% rtB.b4cekmi0wt
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 50;
	
	  ;% rtB.cb01jjmyfq
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 51;
	
	  ;% rtB.fiofh4kefk
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 52;
	
	  ;% rtB.kxk0zjan2u
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 53;
	
	  ;% rtB.eavm2lmu4f
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 54;
	
	  ;% rtB.odntfboinc
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 55;
	
	  ;% rtB.fjd5s1suaw
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 56;
	
	  ;% rtB.grv35kz54w
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 57;
	
	  ;% rtB.pfingzy4pc
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 58;
	
	  ;% rtB.iwds2hww0j
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 59;
	
	  ;% rtB.inr4gxt4lu
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 60;
	
	  ;% rtB.php2zq2lhw
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 61;
	
	  ;% rtB.bcynuxf3b4
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 62;
	
	  ;% rtB.bc2m5qcx30
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 63;
	
	  ;% rtB.gu3pd23vmg
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 64;
	
	  ;% rtB.b0uhmkj3mn
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 65;
	
	  ;% rtB.frbgfp02s3
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 66;
	
	  ;% rtB.frxkjjxjkt
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 67;
	
	  ;% rtB.jw0piz2ncq
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 68;
	
	  ;% rtB.lbzic3bakw
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 70;
	
	  ;% rtB.m33avxegzn
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 72;
	
	  ;% rtB.cnczf5kl3f
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 74;
	
	  ;% rtB.n4pe4taf5k
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 75;
	
	  ;% rtB.f3bhe2mrrl
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 78;
	
	  ;% rtB.aekodpeb5p
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 81;
	
	  ;% rtB.dytwitjqmo
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 82;
	
	  ;% rtB.m2tczfrive
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 84;
	
	  ;% rtB.fxn4vwgtsq
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 86;
	
	  ;% rtB.d1kjzcrxkd
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 87;
	
	  ;% rtB.krjvbt2mq4
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 88;
	
	  ;% rtB.pzqvo3sq2r
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 89;
	
	  ;% rtB.lhqwbn1q25
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 90;
	
	  ;% rtB.plibi3b3wz
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 91;
	
	  ;% rtB.ofl3u43bgw
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 92;
	
	  ;% rtB.c3oz1evhcw
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 93;
	
	  ;% rtB.gfo2bsicyk
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 94;
	
	  ;% rtB.dafsczeyd0
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 95;
	
	  ;% rtB.em31irqwpt
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 113;
	
	  ;% rtB.c4gaogg0kl
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 114;
	
	  ;% rtB.jf2gkiczhf
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 115;
	
	  ;% rtB.n0daf3kfkx
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 116;
	
	  ;% rtB.p40ujyoefj
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 117;
	
	  ;% rtB.dc5nymbuqt
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 119;
	
	  ;% rtB.fikrci5wnj
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 121;
	
	  ;% rtB.pz33wqr5tx
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 122;
	
	  ;% rtB.oiib5ytjjg
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 123;
	
	  ;% rtB.diraslnu04
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 124;
	
	  ;% rtB.jplifgq5sc
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 125;
	
	  ;% rtB.nvfqaxwy3k
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 126;
	
	  ;% rtB.pgkbrhcuia
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 127;
	
	  ;% rtB.bl21y1dth5
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 128;
	
	  ;% rtB.eslj0xnqak
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 129;
	
	  ;% rtB.m5410f2s1r
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 130;
	
	  ;% rtB.dcj3g23bnj
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 131;
	
	  ;% rtB.ekypfbfahe
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 132;
	
	  ;% rtB.gz1es4awfp
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 133;
	
	  ;% rtB.be2hetqlgl
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 134;
	
	  ;% rtB.g0sbc5omlb
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 135;
	
	  ;% rtB.hddv0reyvo
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 136;
	
	  ;% rtB.ftidkuimh2
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 137;
	
	  ;% rtB.b2bhql0adz
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 138;
	
	  ;% rtB.hvj0m54a5e
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 139;
	
	  ;% rtB.dfmiczstqr
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 140;
	
	  ;% rtB.dcpqtuibpu
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 141;
	
	  ;% rtB.c2k2l0344v
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 166;
	
	  ;% rtB.mhkgnw5dfa
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 191;
	
	  ;% rtB.j3gwtsr3ih
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 216;
	
	  ;% rtB.gqdszdjmco
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 221;
	
	  ;% rtB.pubf0ms0bt
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 226;
	
	  ;% rtB.jiyiyrbb4a
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 231;
	
	  ;% rtB.j0j5dylxjw
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 232;
	
	  ;% rtB.jvdtj4iup3
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 233;
	
	  ;% rtB.p2ygvmxt5i
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 234;
	
	  ;% rtB.inhavjn1zx
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 235;
	
	  ;% rtB.gwtwwxhuqy
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 236;
	
	  ;% rtB.i04fclefuh
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 237;
	
	  ;% rtB.cyggjdadcr
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 240;
	
	  ;% rtB.pzj0ccucw1
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 241;
	
	  ;% rtB.ftfak5o3sh
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 242;
	
	  ;% rtB.h0b31s25s4
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 243;
	
	  ;% rtB.ilq0fkqsof
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 244;
	
	  ;% rtB.jsb2lzsy5d
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 245;
	
	  ;% rtB.cheoaxmkwf
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 246;
	
	  ;% rtB.citrubba04
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 247;
	
	  ;% rtB.mg4fjb0upp
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 248;
	
	  ;% rtB.jtyymi0w2q
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 249;
	
	  ;% rtB.f4ykvphd3j
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 250;
	
	  ;% rtB.a5unwbreth
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 251;
	
	  ;% rtB.ggkhauomxo
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 252;
	
	  ;% rtB.pbau2lhp5g
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 277;
	
	  ;% rtB.fbgrxsow4f
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 302;
	
	  ;% rtB.fyyh0ebqhq
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 327;
	
	  ;% rtB.o5bfaqvpcy
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 328;
	
	  ;% rtB.ix4epb55wg
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 330;
	
	  ;% rtB.dlsxci2kgl
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 331;
	
	  ;% rtB.koxeovukjp
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 332;
	
	  ;% rtB.pwe1eclt2g
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 333;
	
	  ;% rtB.lqkqphi04w
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 334;
	
	  ;% rtB.pz1e453xyk
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 335;
	
	  ;% rtB.g50stc2bsg
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 336;
	
	  ;% rtB.nh3cfumtvt
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 337;
	
	  ;% rtB.kmznpd4a0b
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 338;
	
	  ;% rtB.onshuqhaip
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 339;
	
	  ;% rtB.mrxcfcjegz
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 340;
	
	  ;% rtB.onh15amb3y
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 341;
	
	  ;% rtB.ixrm34qqkr
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 342;
	
	  ;% rtB.mkzsniweyj
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 343;
	
	  ;% rtB.kf5ffc0rj1
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 344;
	
	  ;% rtB.en43ee13dp
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 345;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.lxuclx5hmw
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.n5hehfmjzl
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 25;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.gxrfzfobfe
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.ndj0lgd3dt.LoggedData
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.kk3urbel1a
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.h3oborupv1
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDW.jdxobmdxq3
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jstmhifjto
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 23;
	
	  ;% rtDW.a34lmbu2se
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 24;
	
	  ;% rtDW.ii4frt2ihv
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 25;
	
	  ;% rtDW.e1fpigwdyu
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 26;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.gudhnfthi4
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.ecn5ugdake
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtDW.jb3iew0a1q
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.csrztzcibw
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.el4pqea2qg
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.noprxdeo2f
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.frpnm4xhbp
	  section.data(5).logicalSrcIdx = 17;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.njx10umgkj
	  section.data(6).logicalSrcIdx = 18;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3651298471;
  targMap.checksum1 = 610010315;
  targMap.checksum2 = 2930865888;
  targMap.checksum3 = 89649121;

