---
layout: post
title: My Experience
comments: true
permalink: /experience
thread: 1
---

{% include base_path %}

{% for post in site.experience reversed %}
  {% include archive-single.html %}
{% endfor %}
