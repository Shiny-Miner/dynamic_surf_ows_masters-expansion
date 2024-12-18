echo "Running clean"
python3 scripts/clean.py all
echo "Sleeping 3 seconds"
sleep 3
echo "Running make"
python3 scripts/make.py
echo "Sleeping 1 seconds"
