#!/bin/bash

etaBin=(0 1 2 3 4 5)
genEBin=(0 1 2 3 4 5 6 7 8)

#use this command to copy the lines from fileIn.txt to fileOut.txt that only contain the word BIN
#eval "sed -n '/BIN/p' fileIn.txt > fileOut.txt"

#use this command to replace all occurances of 'replaceOne' in fileIn.txt with 'WithTwo' and write
#the result to fileOut.txt
#fileIn.txt does not change
#eval "sed 's/replaceOne/WithTwo/g' fileIn.txt > fileOut.txt"

eval "sed -n '/KEEP/p' neutralKLongGunEnergies_FixedEAndEta.txt > intermediateRefinedNeutralKLongGunEnergies_FixedEAndEta.txt" 
eval "sed 's/KEEP //g' intermediateRefinedNeutralKLongGunEnergies_FixedEAndEta.txt > refinedNeutralKLongGunEnergies_FixedEAndEta.txt"
rm intermediateRefinedNeutralKLongGunEnergies_FixedEAndEta.txt

eval "sed -n '/NO/p' refinedNeutralKLongGunEnergies_FixedEAndEta.txt > intermediate_refinedNoTrackNeutralKLongGunEnergies_FixedEAndEta.txt"
eval "sed 's/NO //g' intermediate_refinedNoTrackNeutralKLongGunEnergies_FixedEAndEta.txt > refinedNoTrackNeutralKLongGunEnergies_FixedEAndEta.txt"
rm intermediate_refinedNoTrackNeutralKLongGunEnergies_FixedEAndEta.txt

#eval "sed -n '/YES/p' refinedNeutralKLongGunEnergies_FixedEAndEta.txt > intermediate_refinedWithTrackNeutralKLongGunEnergies_FixedEAndEta.txt"
#eval "sed 's/YES //g' intermediate_refinedWithTrackNeutralKLongGunEnergies_FixedEAndEta.txt > refinedWithTrackNeutralKLongGunEnergies_FixedEAndEta.txt"
#rm intermediate_refinedWithTrackNeutralKLongGunEnergies_FixedEAndEta.txt

#now I need to use for loops to sort the information in refined**TrackNeutralKLongGunEnergies_FixedEAndEta.txt files
#into many neutralKLongGunEnergies_EGenBin##_EtaBin#_FixedEAndEta.txt files

for i in {0..5}
do
	#loop over the gen particle eta bins
	for j in {0..8}
	do
		#loop over gen energy bins
		eval "sed -n '/ETABIN_${etaBin[$i]} EGENBIN_${genEBin[$j]} /p' refinedNoTrackNeutralKLongGunEnergies_FixedEAndEta.txt > intermediate_refinedNoTrackNeutralKLongGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt"
		eval "sed 's/ETABIN_${etaBin[$i]} EGENBIN_${genEBin[$j]} //g' intermediate_refinedNoTrackNeutralKLongGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt > refinedNoTrackNeutralKLongGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt"
		rm intermediate_refinedNoTrackNeutralKLongGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt
		mv refinedNoTrackNeutralKLongGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt ../energyResoMacroInputFiles/.

		#eval "sed -n '/ETABIN_${etaBin[$i]} EGENBIN_${genEBin[$j]} /p' refinedWithTrackNeutralKLongGunEnergies_FixedEAndEta.txt > intermediate_refinedWithTrackNeutralKLongGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt"
		#eval "sed 's/ETABIN_${etaBin[$i]} EGENBIN_${genEBin[$j]} //g' intermediate_refinedWithTrackNeutralKLongGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt > refinedWithTrackNeutralKLongGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt"
		#rm intermediate_refinedWithTrackNeutralKLongGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt
		#mv refinedWithTrackNeutralKLongGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt ../energyResoMacroInputFiles/.


	done


done



