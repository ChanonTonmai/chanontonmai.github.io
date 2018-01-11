---
layout: archive
title: "My Experience"
permalink: /experience
---

{% include base_path %}

ประสบการ์ณ การท่องเที่ยว และ อื่นๆ

{% capture written_year %}'None'{% endcapture %}
{% for post in site.experience %}
  {% capture year %}{{ post.date | date: '%Y' }}{% endcapture %}
  {% if year != written_year %}
  <h2 id="{{ year | slugify }}" class="archive__subtitle">{{ year }}</h2>
  {% capture written_year %}{{ year }}{% endcapture %}
  {% endif %}
  {% include archive-single.html %}
{% endfor %}
