#!/bin/bash

etaBin=(0 1 2 3 4 5)
genEBin=(0 1 2 3 4 5 6 7 8)

#use this command to copy the lines from fileIn.txt to fileOut.txt that only contain the word BIN
#eval "sed -n '/BIN/p' fileIn.txt > fileOut.txt"

#use this command to replace all occurances of 'replaceOne' in fileIn.txt with 'WithTwo' and write
#the result to fileOut.txt
#fileIn.txt does not change
#eval "sed 's/replaceOne/WithTwo/g' fileIn.txt > fileOut.txt"

eval "sed -n '/KEEP/p' chgdPionGunEnergies_FixedEAndEta.txt > intermediateRefinedChgdPionGunEnergies_FixedEAndEta.txt" 
eval "sed 's/KEEP //g' intermediateRefinedChgdPionGunEnergies_FixedEAndEta.txt > refinedChgdPionGunEnergies_FixedEAndEta.txt"
rm intermediateRefinedChgdPionGunEnergies_FixedEAndEta.txt

eval "sed -n '/NO/p' refinedChgdPionGunEnergies_FixedEAndEta.txt > intermediate_refinedNoTrackChgdPionGunEnergies_FixedEAndEta.txt"
eval "sed 's/NO //g' intermediate_refinedNoTrackChgdPionGunEnergies_FixedEAndEta.txt > refinedNoTrackChgdPionGunEnergies_FixedEAndEta.txt"
rm intermediate_refinedNoTrackChgdPionGunEnergies_FixedEAndEta.txt

#eval "sed -n '/PT/p' refinedChgdPionGunEnergies_FixedEAndEta.txt > intermediate_refinedNoTrackChgdPionGunEnergies_FixedPtAndEta.txt"
#eval "sed 's/PT //g' intermediate_refinedNoTrackChgdPionGunEnergies_FixedPtAndEta.txt > refinedNoTrackChgdPionGunEnergies_FixedPtAndEta.txt"
#rm intermediate_refinedNoTrackChgdPionGunEnergies_FixedPtAndEta.txt


eval "sed -n '/YES/p' refinedChgdPionGunEnergies_FixedEAndEta.txt > intermediate_refinedWithTrackChgdPionGunEnergies_FixedEAndEta.txt"
eval "sed 's/YES //g' intermediate_refinedWithTrackChgdPionGunEnergies_FixedEAndEta.txt > refinedWithTrackChgdPionGunEnergies_FixedEAndEta.txt"
rm intermediate_refinedWithTrackChgdPionGunEnergies_FixedEAndEta.txt

#now I need to use for loops to sort the information in refined**TrackChgdPionGunEnergies_FixedEAndEta.txt files
#into many chgdPionGunEnergies_EGenBin##_EtaBin#_FixedEAndEta.txt files

for i in {0..5}
do
	#loop over the gen particle eta bins
	for j in {0..8}
	do
		#loop over txt files with energy values 
		eval "sed -n '/ETABIN_${etaBin[$i]} EGENBIN_${genEBin[$j]} /p' refinedNoTrackChgdPionGunEnergies_FixedEAndEta.txt > intermediate_refinedNoTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt"
		eval "sed 's/ETABIN_${etaBin[$i]} EGENBIN_${genEBin[$j]} //g' intermediate_refinedNoTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt > refinedNoTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt"
		rm intermediate_refinedNoTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt
		mv refinedNoTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt ../energyResoMacroInputFiles/.

		eval "sed -n '/ETABIN_${etaBin[$i]} EGENBIN_${genEBin[$j]} /p' refinedWithTrackChgdPionGunEnergies_FixedEAndEta.txt > intermediate_refinedWithTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt"
		eval "sed 's/ETABIN_${etaBin[$i]} EGENBIN_${genEBin[$j]} //g' intermediate_refinedWithTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt > refinedWithTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt"
		rm intermediate_refinedWithTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt
		mv refinedWithTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedEAndEta.txt ../energyResoMacroInputFiles/.

		#loop over txt files with pT values 
		#eval "sed -n '/ETABIN_${etaBin[$i]} EGENBIN_${genEBin[$j]} /p' refinedNoTrackChgdPionGunEnergies_FixedPtAndEta.txt > intermediate_refinedNoTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedPtAndEta.txt"
		#eval "sed 's/ETABIN_${etaBin[$i]} EGENBIN_${genEBin[$j]} //g' intermediate_refinedNoTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedPtAndEta.txt > refinedNoTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedPtAndEta.txt"
		#rm intermediate_refinedNoTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedPtAndEta.txt
		#mv refinedNoTrackChgdPionGun_EGenBin${genEBin[$j]}_EtaBin${etaBin[$i]}_FixedPtAndEta.txt ../ptResoMacroInputFiles/.



	done


done

rm refinedNoTrackChgdPionGunEnergies_FixedEAndEta.txt refinedChgdPionGunEnergies_FixedEAndEta.txt
#rm refinedNoTrackChgdPionGunEnergies_FixedPtAndEta.txt refinedWithTrackChgdPionGunEnergies_FixedEAndEta.txt



