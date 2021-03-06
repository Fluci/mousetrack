# This file creates a realistic file structure as generated by the matlab script
# The files contain minimum data to be useful

ROOT=`pwd`

BASES_SF="depth depth_normalized pic"
BASES_F="params"
SINGLES="params_R.csv params_camchain.csv"

STREAMS="1 2 3 4"
FRAMES="17 18"

TARGET_DIR="${ROOT}/mock_data"

# create target directory
mkdir -p ${TARGET_DIR}
# make sure directory is empty
rm -rf ${TARGET_DIR}/*

# TODO: investigate if cp could be replaced with ln -s (Windows? regular file?)
# CP=cp
CP="ln -s"
# create images
for B in ${BASES_SF}; do
	for S in ${STREAMS}; do
		for F in ${FRAMES}; do
			${CP} ${ROOT}/grey1x1.png ${TARGET_DIR}/${B}_s_${S}_f_${F}.png
		done
	done
done

# create param files

for B in ${BASES_F}; do
	for F in ${FRAMES}; do
		${CP} ${ROOT}/${B}_base.csv ${TARGET_DIR}/${B}_f_${F}.csv
	done
done


# create single files

for S in ${SINGLES}; do
	${CP} ${ROOT}/${S} ${TARGET_DIR}/${S}
done
