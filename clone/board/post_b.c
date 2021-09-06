// bboard.c

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")
#define TEXT_LINE "����������������������������������������������������������������������"

inherit ITEM;
inherit F_SAVE;

void setup()
{
	string loc;

	if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
	restore();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_read", "read");
	add_action("do_discard", "discard");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " �� û���κ����� �� ";

	if( this_player() ) {
		last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		return sprintf("%s�� %d �����ԣ�%d ��δ�� ��", ::short(), sizeof(notes), unread);
	else
		return sprintf("%s�� %d ������ ��", ::short(), sizeof(notes));
}

string long()
{
	return ::long() + @LONG
���԰��ʹ�÷�����
list [���Ա��|new]      : �鿴���Ա���
read <���Ա��|new|next> : �鿴���Ա���
discard <���Ա��>       : ɾ������
LONG;
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note)
{
	mapping *notes;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(notes) > BOARD_CAPACITY )
		notes = notes[BOARD_CAPACITY / 2 .. BOARD_CAPACITY];

	set("notes", notes);
	save();
	return;
}

int do_read(string arg)
{
	int num;
	mapping *notes, last_read_time;
	string myid;

	last_read_time = this_player()->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("���԰���Ŀǰû���κ����ԡ�\n");

	if( !arg ) return notify_fail("ָ���ʽ��read <���Ա��|new|next>\n");
	if( arg=="new" || arg=="next" ) {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;

	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("��Ҫ���ڼ������ԣ�\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("û���������ԡ�\n");
	num--;
	/*
	this_player()->start_more( sprintf("[%d] %-=36s %18s (%s)\n"
	"-------------------------------------------------------------------------------\n",
		num + 1, notes[num]["title"], notes[num]["author"],
		ctime(notes[num]["time"])[0..15])
		+ notes[num]["msg"] );
	*/
	this_player()->start_more(sprintf(HIW"\n��ţ�"NOR"%-3d\n"HIW"���ߣ�"NOR"%-54s"HIW"ʱ�䣺"NOR"%s\n"HIW"���⣺"NOR"%s\n%s\n%s",
        num + 1, notes[num]["author"], ctime(notes[num]["time"])[0..15],
        notes[num]["title"], TEXT_LINE +"������������", notes[num]["msg"] + TEXT_LINE + "[ �� ƪ �� ]\n"));

	// Keep track which post we were reading last time.
	if( !mapp(last_read_time) )
		this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	return 1;
}


int do_discard(string arg)
{
	object me=this_player();
	mapping *notes;
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("ָ���ʽ��discard <���Ա��>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("û���������ԡ�\n");
	num--;
	if( notes[num]["author"] != me->query("name") + "("+me->query("id")+")"
	&& SECURITY_D->get_status(me) != "(admin)"
	&& SECURITY_D->get_status(me) != "(assist)"
	&& SECURITY_D->get_status(me) != "(arch)")
		return notify_fail("������Բ�����д�ġ�\n");

	notes = notes[0..num-1] + notes[num+1..<1];
	set("notes", notes);
	save();
	write("ɾ���� " + (num+1) + " ������....Ok��\n");
	return 1;
}

int do_list(string arg)
{
	mapping *notes, last_read_time = 0;
	int num, i, last_time_read, width;
	string msg = "", myid;

	notes = query("notes");
	last_read_time = this_player()->query("board_last_read");
	myid = query("board_id");
	if ( !arg || sscanf(arg, "%d", num)!=1 || num < 1 ) num = 1;
	if ( arg == "new") {
		arg = 0;
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;
	};

	if (num > sizeof(notes)) return notify_fail("û����Ҫ�����ԡ�\n");
	if (mapp(last_read_time)) last_time_read = last_read_time[myid];
	width = strlen(sizeof(notes)+"");
	for(i=num-1; i<sizeof(notes); i++) {
		if (arg == "me"
			&& strsrch(notes[i]["author"], "("+this_player()->query("id")+")") < 0)
			continue;
		if (arg && !sscanf(arg, "%*d") && arg != "me" && strsrch(notes[i]["author"], arg) < 0)
			continue;
		msg += sprintf("%s[%*d]" NOR,
			notes[i]["time"] > last_time_read ? HIY: "",
			width, i+1);
		msg += (sprintf("     %-=36s %18s (%s)\n",
			notes[i]["title"], notes[i]["author"],
			ctime(notes[i]["time"])[0..15] ))[5..<0];
	}
	this_player()->start_more(msg);
	return 1;
}

void create()
{
	set("board_id", "post_b");
	set("location", "/d/wizard/wizard_meet");
	setup();
    set_name("�齣���԰��ܻ�", ({ "board" }) );
	set("long", "���ǻ㼯��������������Ե����԰塣\n" );
	set("capacity", 999);
}
