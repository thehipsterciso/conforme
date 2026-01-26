# conforme

**Conforme** is a C++ library purpose-built to **build, consume, process, validate, and manage Open Vulnerability Assessment Language (OVAL) content**.

This codebase was developed to support the **authoring, validation, and lifecycle management of OVAL submissions presented to MITRE and CIS**, with an explicit focus on correctness, determinism, and standards fidelity. It was not intended to be a generic XML toolkit; it is a domain-specific implementation designed for practitioners who actually ship OVAL data.

If you are generating OVAL content that must survive formal review, schema validation, and real-world operational use, this library exists for you.

## Why this exists

OVAL authoring is deceptively difficult:
	•	The specification is strict and unforgiving  
	•	Tooling is fragmented and often opaque  
	•	Reference implementations optimize for consumption, not authorship  
	•	Small semantic errors invalidate entire submissions  

Conforme was created to close that gap.

## Component overview
	•	Conforme
  	•	Core data structures
  	•	Shared utilities
  	•	Cross-module abstractions
	•	ConformeOVAL
  	•	OVAL schema-aligned models
  	•	Builders and processors
  	•	Authoring-centric logic for definitions and tests
	•	ConformeXML
  	•	Deterministic XML parsing
  	•	Controlled serialization
  	•	Namespace- and schema-aware handling

## Intended usage patterns

1. OVAL authoring pipelines (primary use case)
Use Conforme to:
	•	Programmatically generate OVAL content
	•	Validate artifacts before submission
	•	Enforce internal quality gates prior to publication

This is how the library was originally used for MITRE and CIS submissions.

2. Toolchain integration
Embed Conforme into:
	•	Compliance automation platforms
	•	Vulnerability content factories
	•	Internal standards pipelines
	•	CI/CD workflows enforcing security baselines

Conforme is not optimized for:
	•	Lightweight scanning engines
	•	Casual OVAL interpretation
	•	Lenient parsing of malformed content

It exists to produce and manage submission-grade OVAL, not to excuse bad inputs.

## Provenance

This library was developed in the course of real OVAL authoring work, including submissions presented to:
	•	MITRE
	•	Center for Internet Security (CIS)

It reflects practical lessons learned from interacting and contributing to the specification and review processes.
