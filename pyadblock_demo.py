from pyadblock import AdBlockClient, FilterOption

c = AdBlockClient()

print("-- Parsing filterlist - takes a while.")
with open('test/data/easylist.txt', 'r') as f:
    easylist = f.read()
c.parse(easylist)

print(f"""
Properties:
  - numFilters: {c.numFilters}
  - numCosmeticFilters: {c.numCosmeticFilters}
  - numHtmlFilters: {c.numHtmlFilters}
  - numExceptionFilters: {c.numExceptionFilters}
  - numNoFingerprintFilters: {c.numNoFingerprintFilters}
  - numNoFingerprintExceptionFilters: {c.numNoFingerprintExceptionFilters}
  - numNoFingerprintDomainOnlyFilters: {c.numNoFingerprintDomainOnlyFilters}
  - numNoFingerprintAntiDomainOnlyFilters: {c.numNoFingerprintAntiDomainOnlyFilters}
  - numNoFingerprintDomainOnlyExceptionFilters: {c.numNoFingerprintDomainOnlyExceptionFilters}
  - numNoFingerprintAntiDomainOnlyExceptionFilters: {c.numNoFingerprintAntiDomainOnlyExceptionFilters}
  - numHostAnchoredFilters: {c.numHostAnchoredFilters}
  - numHostAnchoredExceptionFilters: {c.numHostAnchoredExceptionFilters}
""")


print("-- Testing")

curdomain = 'slashdot.org'
test_urls = [
    # Blocked by: ||pagead2.googlesyndication.com^$~object-subrequest
    "http://pagead2.googlesyndication.com/pagead/show_ads.js",
    # Blocked by: ||googlesyndication.com/safeframe/$third-party
    "http://tpc.googlesyndication.com/safeframe/1-0-2/html/container.html",
    # Blocked by: ||googletagservices.com/tag/js/gpt_$third-party
    "http://www.googletagservices.com/tag/js/gpt_mobile.js",
    # Not blocked
    "http://www.brianbondy.com"
]
expected = [True, True, True, False]

results = []
for url, e in zip(test_urls, expected):
    actual = c.matches(url, FilterOption.FONoFilterOption, curdomain)
    assert actual == e, f"Failed for url {url}. Expected {e}, but got {actual}."
    results.append(actual)

print(f"Success")
