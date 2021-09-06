// /clone/board/wizto_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("����Ա����������񹫸��", ({ "board" }) );
        set("location", "/d/city/chmiao");
	set("board_id", "wizto_b");
	set("long", "����һ������Ա�����������Ĺ������԰壬��Ҳ������ԡ�\n" );
	setup();
	set("capacity", 500);
}

int do_post(string arg)
{
	if (!wizardp(this_player()))
		return notify_fail("ֻ����ʦ�ſ������������ԡ�\n");

	return ::do_post(arg);
}
void auto_post(string title,string text) {
        mapping note;
        object POSTER;
        if( objectp(POSTER=load_object("/clone/board/wizto_b")) )
        {
                 note=([]);
                 note["title"] = title;;
                 note["author"] = sprintf("%s(%s)",this_player()->query("name"),this_player()->query("id"));
                 note["time"] = time();
                 POSTER->done_post2(this_player(),note,text);
          }
       return;
 }
 void done_post2(object me, mapping note, string text)
{
        mapping *notes;

        note["time"] = time();
        note["msg"] = text;
        notes = query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                notes = ({ note });
        else
                notes += ({ note });

        // Truncate the notes if maximum capacity exceeded.
        if( sizeof(notes) > query("capacity") )
                notes = notes[query("capacity")/ 2 .. query("capacity")];

        set("notes", notes);
        save();
        note = copy(note);
        note["msg"] = "���� " + ::short() + "\n" + text;
        "/clone/board/post_b"->done_post(me, note);
        tell_object(me,"������¼�Ѿ�����������Ա����������񹫸�塣\n");
}
