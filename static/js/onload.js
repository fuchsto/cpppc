$(document).ready(function() {
  MathJax.Hub.Config({
    extensions: ["tex2jax.js","TeX/AMSmath.js","TeX/AMSsymbols.js"],
    TeX: {
      TagSide: "right",
      TagIndent: ".8em",
      MultLineWidth: "85%",
      equationNumbers: {
         autoNumber: "AMS",
      },
      unicode: {
         fonts: "STIXGeneral,'Arial Unicode MS'" 
      },
      Macros: {
         divz: '{ \\,\\div_{z}\\, }',
         divi: '{\\underset{\\mapsto 0}{\\text{ div }}}',
         braket: ['{\\langle #1 \\rangle}', 1],
         Abs: ['\\left\\lvert #2 \\right\\rvert_{\\text{#1}}', 2, ""],
         tmod: '{\\text{ mod }}',
         Floor: ['{\\left\\lfloor #1 \\right\\rfloor}', 1],
         Ceil: ['{\\left\\lceil #1 \\right\\rceil}', 1]
      },
    },
    "HTML-CSS": {
      preferredFont: "STIX",
      webFont: null,
      scale: 95,
      mtextFontInherit: false,
      matchFontHeight: false,
//    displayAlign: "left"
    }
  });

  $('h2').each(
    function(idx, elem) {
      console.log('at ' + $(elem).attr('id'));
      $(elem).append('<div class="expand-button">+</div>');
      $(elem).append('<div class="collapse-button">-</div>');
      $(elem).children('.expand-button').hide();
      $(elem).click(
        function() {
          $(this).nextUntil('h1, h2').toggle();
          $(this).children('.collapse-button').toggle();
          $(this).children('.expand-button').toggle();
          $(this).toggleClass('collapsed');
        });
      $(elem).click();
    });
});
