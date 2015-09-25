$(function() {

    var textarea = $('textarea[data-editor]')[0];

    if(!textarea)
        return ;

    var mode = $(textarea).attr("data-editor")

    var editor = ace.edit(textarea);

    textarea = $(textarea)
    editor.getSession().setUseWorker(true);
    editor.getSession().setUseWrapMode(true);
    editor.setHighlightActiveLine(true);
    editor.renderer.setShowGutter(true)
    editor.setFontSize('16px')
    editor.getSession().setValue(textarea.val())
    editor.getSession().setMode("ace/mode/" + (mode ? mode : "javascript"))
    editor.setTheme("ace/theme/eclipse")

    // copy back to textarea on form submit...
    textarea.closest('form').submit(function () {
        textarea.val(editor.getSession().getValue());
    })

    $('#save_code').click(function() {
        console.log(textarea.val())
        textarea.val(editor.getSession().getValue())
        $('#code').val(editor.getSession().getValue())
    })
    editor.getSession().on('load', function() {
        textarea.val(editor.getSession().getValue())
        $('#code').val(editor.getSession().getValue());
    })
    editor.getSession().on('change', function() {
        textarea.val(editor.getSession().getValue())
        $('#code').val(editor.getSession().getValue());
    })

    $('a.bbcode').click(function (e) {
        e.preventDefault()

        var code = $(this).attr('data-editor'), range = editor.getSelectionRange()
        var selection = editor.session.getTextRange(range),
                t
        var bb = ['b','i','u', 's']
        for(var k in bb)
        {
            if(bb[k] == code.toLowerCase())
            {
                editor.insert(
                            '[' + code.toUpperCase() + ']' + selection,
                            selection.start
                            )
                editor.insert('[/' + code.toUpperCase() + ']', range.end)
                if (!selection) {
                    var selLead = editor.session.getSelection().selectionLead
                    selLead.setPosition(selLead.row, selLead.column - code.length - 3)
                }
                else
                    editor.find(selection, range)
                editor.focus()
                return
            }
        }
        if(code.toLowerCase() == 'url' || code.toLowerCase() == 'img')
        {
            t = prompt('Введите url ' + (code.toLowerCase() == 'img' ? 'к изображению' : ''), 'http://')
            if(!t)
                return
            if(t && !selection)
                selection = t
            editor.insert(
                        '[' + code.toUpperCase() + '="' + t + '"]' + selection,
                        selection.start
                        )
            editor.insert('[/' + code.toUpperCase() + ']', range.end)
            editor.focus()
            return
        }
        editor.insert(
                    '[' + code.toUpperCase() + ']' + selection,
                    selection.start
                    )
        editor.insert('[/' + code.toUpperCase() + ']', range.end)
        if (!selection) {
            var selLead = editor.session.getSelection().selectionLead
            selLead.setPosition(selLead.row, selLead.column - code.length - 3)
        }
        else
            editor.find(selection, range)

        editor.focus()


        if (!code)
            code = 'javascript'
        editor.getSession().setMode('ace/mode/' + code)
    })
})
