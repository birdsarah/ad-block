#include <pybind11/pybind11.h>
#include "ad_block_client.h"

PYBIND11_MODULE(pyadblock, m) {
    pybind11::enum_<FilterOption>(m, "FilterOption")
        .value("FONoFilterOption", FilterOption::FONoFilterOption)
        .value("FOScript", FilterOption::FOScript)
        .value("FOImage", FilterOption::FOImage)
        .value("FOStylesheet", FilterOption::FOStylesheet)
        .value("FOObject", FilterOption::FOObject)
        .value("FOXmlHttpRequest", FilterOption::FOXmlHttpRequest)
        .value("FOObjectSubrequest", FilterOption::FOObjectSubrequest)
        .value("FOSubdocument", FilterOption::FOSubdocument)
        .value("FODocument", FilterOption::FODocument)
        .value("FOOther", FilterOption::FOOther)
        .value("FOXBL", FilterOption::FOXBL)
        .value("FOCollapse", FilterOption::FOCollapse)
        .value("FODoNotTrack", FilterOption::FODoNotTrack)
        .value("FOElemHide", FilterOption::FOElemHide)
        ;
    pybind11::class_<AdBlockClient>(m, "AdBlockClient")
        .def(pybind11::init<>())
        .def("parse", &AdBlockClient::parse)
        .def("matches", &AdBlockClient::matches)
        .def_readonly("numFilters", &AdBlockClient::numFilters)
        .def_readonly("numCosmeticFilters", &AdBlockClient::numCosmeticFilters)
        .def_readonly("numHtmlFilters", &AdBlockClient::numHtmlFilters)
        .def_readonly("numExceptionFilters", &AdBlockClient::numExceptionFilters)
        .def_readonly("numNoFingerprintFilters", &AdBlockClient::numNoFingerprintFilters)
        .def_readonly("numNoFingerprintExceptionFilters", &AdBlockClient::numNoFingerprintExceptionFilters)
        .def_readonly("numNoFingerprintDomainOnlyFilters", &AdBlockClient::numNoFingerprintDomainOnlyFilters)
        .def_readonly("numNoFingerprintAntiDomainOnlyFilters", &AdBlockClient::numNoFingerprintAntiDomainOnlyFilters)
        .def_readonly("numNoFingerprintDomainOnlyExceptionFilters", &AdBlockClient::numNoFingerprintDomainOnlyExceptionFilters)
        .def_readonly("numNoFingerprintAntiDomainOnlyExceptionFilters", &AdBlockClient::numNoFingerprintAntiDomainOnlyExceptionFilters)
        .def_readonly("numHostAnchoredFilters", &AdBlockClient::numHostAnchoredFilters)
        .def_readonly("numHostAnchoredExceptionFilters", &AdBlockClient::numHostAnchoredExceptionFilters)
        ;
}
