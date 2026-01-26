# conforme

**Conforme** is a C++ library purpose-built to **build, consume, process, validate, and manage Open Vulnerability Assessment Language (OVAL) content**. [CIS OVAL REPO](https://github.com/CISecurity/OVALRepo) 

The library was developed to support the **authoring, validation, and lifecycle management of OVAL submissions presented to MITRE and the Center for Internet Security (CIS)**, with an explicit emphasis on correctness, determinism, and strict standards adherence. It is not a generic XML toolkit. It is a domain-specific implementation designed for practitioners who produce and maintain submission-grade OVAL content. 

If you are generating OVAL artifacts that must withstand formal review, schema validation, and real-world operational use, this library exists to support that outcome.

## Why this exists

OVAL authoring is deceptively complex:

- The specification is strict and unforgiving
- Tooling is fragmented, inconsistent, and often opaque
- Most reference implementations optimize for *consumption*, not *authorship*
- Minor semantic errors can invalidate entire submissions

Conforme was created to close this gap by treating OVAL content as an engineered artifact rather than a hand-crafted document.

## Component overview

### Conforme
- Core data structures
- Shared utilities
- Cross-module abstractions

### ConformeOVAL
- OVAL schema-aligned domain models
- Builders and processors
- Authoring-centric logic for definitions, tests, and related constructs

### ConformeXML
- Deterministic XML parsing
- Controlled and predictable serialization
- Namespace- and schema-aware handling

## Intended usage patterns

### 1. OVAL authoring pipelines (primary use case)

Use Conforme to:
- Programmatically generate OVAL content
- Validate artifacts prior to submission
- Enforce internal quality gates before publication

This reflects the original use of the library in support of MITRE and CIS submissions.

### 2. Toolchain integration

Embed Conforme into:
- Compliance automation platforms
- Vulnerability content generation pipelines
- Internal standards and assurance workflows
- CI/CD processes enforcing security baselines

Conforme is **not** optimized for:
- Lightweight or embedded scanning engines
- Casual or exploratory OVAL interpretation
- Lenient parsing of malformed or non-compliant content

Its purpose is to produce and manage **submission-grade OVAL**, not to normalize invalid inputs.

## Provenance

This library was developed through hands-on OVAL authoring work, including submissions presented to:

- [MITRE](https://github.com/MITRE)
- [Center for Internet Security (CIS)](https://github.com/CISecurity)

It reflects practical lessons learned from contributing to, validating against, and navigating formal OVAL specification and review processes.
