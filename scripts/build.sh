echo "Running clean"
python3 scripts/clean.py all
echo "Sleeping 1 seconds"
sleep 1
echo "Running make"
python3 scripts/make.py
echo "Sleeping 1 seconds"
