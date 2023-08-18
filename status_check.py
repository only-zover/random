import requests

URL = "https://geo.londrina.pr.gov.br/"
TIMEOUT_TIME = 10

def verifyStatus(url):
	"""Check if the url status is ok.

	url (str): url to be checked 
	"""
	try:
		response = requests.get(url, timeout = TIMEOUT_TIME)
		response.raise_for_status()
		return True
	except requests.exceptions.Timeout as to:
		print(to)
	except requests.exceptions.ConnectionError as ce:
		print(ce)
	except requests.exceptions.HTTPError as he:
		print(he)
	except requests.exceptions.RequestException as re:
		print(re)
	return False
	
verifyStatus(URL)
