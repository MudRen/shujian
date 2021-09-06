// bboard.c modify by XiaoYao 01/10/2000
// modify by linux 10/17/2003 �������Իظ�
// Modified by Ciwei@SJ 5/8/2004 ��bbs����

inherit ITEM;
inherit F_SAVE;

#include <ansi.h>
#include <board.h>
#include <mudlib.h>

#define BOARD_CAPACITY query("capacity")
#define TEXT_LINE "����������������������������������������������������������������������"
#ifndef BBS_ADDR
#define BBS_ADDR "http://bbs.mymud.com"
#endif
#define BBS_OK(x) sprintf(WHT"%s������̳��ɡ�\n"NOR,x)
#define BBS_URL(x) sprintf(CYN"�����������%s/viewthread.php?tid=%d��\n"NOR,BBS_ADDR,x)

void setup()
{
        string loc;

        ::setup();
        if( stringp(loc = query("location")) )
                move(loc);
        set("no_sac", 1);
        set("no_get", 1);
        restore();
        set("location", loc);
}

void init()
{
        add_action("do_post", "post");
        add_action("do_read", "read");
        add_action("do_list", "list");
        add_action("do_discard", "discard");
        add_action("do_re", "re");
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
                return ::short() + " �� û���κ����� ��";

        if( this_player() ) {
                last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
                for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
                        if( notes[i]["time"] <= last_read_time ) break;
        }
        if( unread )
                return sprintf("%s �� %d �����ԣ�"HIY"%d "NOR"��"HIR"δ��"NOR" ��", ::short(), sizeof(notes), unread);
        else
                return sprintf("%s �� %d ������ ��", ::short(), sizeof(notes));
}

string long()
{
        return ::long() + @LONG
���԰��ʹ�÷�����
list [���Ա��|new]     : �鿴���Ա���
post <����>             : ����
read <���Ա��|new|next>: �鿴��������
discard <���Ա��>      : ɾ������
LONG;
}

nosave int op;

void post_ok(mixed ret)
{
	mapping *notes;
	
	if(environment()) tell_room(environment(),BBS_OK("����"));
	notes = query("notes");
	if(!notes || !sizeof(notes)) return;
	if(op != sizeof(notes)-1) return;//have somebody change it
	if(!ret || !sizeof(ret)) return;
	notes[op]["tid"] = ret[0][0];
	if(environment()) tell_room(environment(),BBS_URL(ret[0][0]));
	save();
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
        mapping *notes;

        note["time"] = time();
        note["msg"] = text;
        //ת�������ַ�
        note["title"] = specialchars(note["title"]);
        text = specialchars(text);
        //ת�������ַ�����
        if(query("board_id") && !undefinedp(BOARD_FID[query("board_id")]))
		BBS_D->bbs_post(BOARD_FID[query("board_id")],wizardp(me)?me->query("id"):me->query("id")+"@"+lower_case(INTERMUD_MUD_NAME),note["title"],"������"+CHINESE_MUD_NAME+::short() + "\n\n" + text,0,0,0,this_object(),"post_ok" );
        
        notes = query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                notes = ({ note });
        else
                notes += ({ note });
	
	op = sizeof(notes)-1;
        // Truncate the notes if maximum capacity exceeded.
        if( sizeof(notes) > BOARD_CAPACITY )
                notes = notes[BOARD_CAPACITY / 2 .. BOARD_CAPACITY];

        set("notes", notes);
        save();
        note = copy(note);
        note["msg"] = "���� " + ::short() + "\n" + text;
        "/clone/board/post_b"->done_post(me, note);

        tell_object(me, TEXT_LINE + WHT"[ E n d ]\n"NOR);
        tell_object(me, "������ϡ�\n");        
        me->add_busy(1);
}

void re_ok(mixed ret)
{
	if(environment()) tell_room(environment(),BBS_OK("�ظ�"));
	if(ret && sizeof(ret)) if(environment()) tell_room(environment(),BBS_URL(ret[0][0]));
}

void done_re(object me, mapping report, int project, string text)
{
	mapping *notes, *reports;
	int i;
        string *lines;

        if (! stringp(text))
                return;

        if (strlen(text) > 64 * 1024)
        {
                tell_object(me, "�������̫���ˣ�����ȥһЩ����Ҫ�ġ�\n");
                return;
        }

        lines = explode(text, "\n");
        i = sizeof(lines);
        if (i > 2000)
        {
                tell_object(me, "�������̫���ˣ�����ȥһЩ����Ҫ�ġ�\n");
                return;
        }

        if (i > 20 && strlen(text) / i < 10)
        {
                tell_object(me, "��������ж̾�̫���ˣ������һ���Ա������Ķ���\n");
                return;
        }

        while (i--)
        {
                // scan all lines
                if (strlen(lines[i]) > 300)
                {
                        tell_object(me, "����������Щ��̫���ˣ�������Ա������Ķ���\n");
                        return;
                }
        }

        wizardp(me)?report["msg"] = HIG+text+NOR:report["msg"] = text;
	notes = query("notes");
	reports = notes[project]["re"];
	
	report["title"] = specialchars(report["title"]);
	text = specialchars(text);
	
	text = "������"+CHINESE_MUD_NAME+::short() + "\n\n" + text;
	if(query("board_id") && !undefinedp(BOARD_FID[query("board_id")]) && !undefinedp(notes[project]["tid"]) && notes[project]["tid"] )
		BBS_D->bbs_post(BOARD_FID[query("board_id")],wizardp(me)?me->query("id"):me->query("id")+"@"+lower_case(INTERMUD_MUD_NAME),report["title"],text,notes[project]["tid"],0,0,this_object(),"re_ok" );
	
	if( !arrayp(reports) )	reports = ({ report });
	else reports += ({ report });

	notes[project]["re"] = reports;
	notes[project]["time"] = time();

	set("notes", notes);
	tell_object(me,"������������������������������������������������������������������[ �ظ����� ]\n");

	save();
	return;
}
int do_post(string arg)
{
        mapping note;
        int i;
        object me;

        if( !arg ) return notify_fail("������ָ��һ�����⡣\n");

        me = this_player();
        if (me->is_busy())
                return notify_fail("����æ���ء�\n");
        i = strlen(arg);
        if( !wizardp(me) ){
                if (i < 4 || i > 24 || i%2) {
                        write("�Բ��𣬱�������� 2 �� 12 �������֡�\n");
                        return 0;
                }

                while(i--)
                        if (i%2==0 && !is_chinese(arg[i..<1])) {
                                write("�Բ��������á����ġ�ȡ���⡣\n");
                                return 0;
                        }
        }
        else if( i > 24 )
                return notify_fail("��ı���̫���ˣ���������ı��⡣\n");

        note = allocate_mapping(4);
        note["title"] = arg;
        note["author"] = me->query("name") + "(" + me->query("id") + ")";        
        me->edit( (: done_post, me, note :) );
        return 1;
}

int do_read(string arg)
{
        int num,j;
        mapping *notes, last_read_time;
        string myid;
        string msg = "";

        last_read_time = this_player()->query("board_last_read");
        myid = query("board_id");
        notes = query("notes");

        if( !pointerp(notes) || !sizeof(notes) )
                return notify_fail("���԰���Ŀǰû���κ����ԡ�\n");

        if( !arg ) return notify_fail("ָ���ʽ��read <���Ա��>|new|next\n");
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
        
        if(notes[num]["tid"])
        	msg += "\n"+ BBS_URL(notes[num]["tid"]);
                
        if (sizeof(notes[num]["re"])) {
				for (j=0;j<sizeof(notes[num]["re"]);j++) {
					msg+=sprintf(
					"\n%s �� %s �ظ����£�"NOR" %s\n"
					TEXT_LINE +"\n"
					"%s\n",
					notes[num]["re"][j]["author"]+"("+
					notes[num]["re"][j]["owner"]+")",
					ctime(notes[num]["re"][j]["time"])[0..15],
					notes[num]["re"][j]["title"],
					notes[num]["re"][j]["msg"],);
				}
			}		
			
        this_player()->start_more(sprintf(HIW"��ţ�"NOR"%-4d "HIW"���ߣ�"NOR"%-35s"HIW"ʱ�䣺"NOR"%s\n"HIW"���⣺"NOR"%s\n%s\n%s",
        num + 1, notes[num]["author"], ctime(notes[num]["time"]),
        notes[num]["title"], TEXT_LINE +"������������", notes[num]["msg"] + msg + TEXT_LINE + "[ �� ƪ �� ]\n"));

        // Keep track which post we were reading last time.
        if( !mapp(last_read_time) )
                this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
        else
                if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
                        last_read_time[myid] = notes[num]["time"];

        return 1;
}

int do_re(string arg)
{
	int num;
	string title;
	mapping note, *notes;
	object me=this_player();
	
	if (!wizardp(me)) return 0;

	if(!arg || sscanf(arg, "%d.%s", num, title)<1)
		return notify_fail("ָ���ʽ��re <���ӱ��>.<�ظ�����>\n");

	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("û��������ӡ�\n");

	if (strlen(title) > 30)
		return notify_fail("����ظ�����̫���ˣ��뻻һ�����һ��ġ�\n");


	if (!title) title="Re: "+notes[num-1]["title"];

	note = allocate_mapping(5);
	note["title"] = title;
	note["owner"] = me->query("id");
	note["author"] = me->name(1);
	note["time"] = time();
	me->edit( (: done_re, me, note, num-1 :) );
	return 1;
}
int do_discard(string arg)
{
        object me=this_player(1);
        mapping *notes;
        int num;

        if( !arg || sscanf(arg, "%d", num)!=1 )
                return notify_fail("ָ���ʽ��discard <���Ա��>\n");
        notes = query("notes");
        if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
                return notify_fail("û���������ԡ�\n");
        num--;
        if (notes[num]["author"] != me->query("name") + "("+me->query("id")+")"
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
        for(i = num-1; i < sizeof(notes); i++) {
                if (arg == "me"
                        && strsrch(notes[i]["author"], "("+this_player()->query("id")+")") < 0)
                        continue;
                if (arg && !sscanf(arg, "%*d") && arg != "me" && strsrch(notes[i]["author"], arg) < 0)
                        continue;
                msg += sprintf("%s[%*d]" NOR,
                        notes[i]["time"] > last_time_read ? HIY: "",
                        width, i+1);
                msg += (sprintf("     %-=39s %18s (%s)\n",
                        notes[i]["title"], notes[i]["author"],
                        ctime(notes[i]["time"])[3..15] ))[4..<0];
        }
        this_player()->start_more(msg);
        return 1;
}
