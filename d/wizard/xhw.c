#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","С����");
        set("long",
"������С���ݣ�ר���÷������ұ���˼���ġ�
ǽ���ƺ���ģ�����ּ�����ϸ��֮�£������ƺ�д������ʲݵ��ּ���ϸϸ��ȥ����Ȼ�ǡ������澭����
����һ��ǽ�Ͽ̻������С�ˣ��ֳֳ�������ʽ�������£���ϡ���Ƕ��¾Ž�����ʽ��
");
        set("no_update", 1);
        set("no_fight", 1);
        set("no_sleep_room", 1);
        set("sleep_room", 1);
        set("valid_startroom", 1);
        set("no_get",1);
        set("no_dazuo",1);
        setup();
}
void init()
{
        add_action("do_quit","suicide");      
        add_action("do_quit","exert");
        add_action("do_quit","exercise");
        add_action("do_quit","get");
        add_action("do_quit2","quit");
        add_action("do_quit2","exit");
        add_action("do_quit2","exercise");
        add_action("do_quit2","halt");
        add_action("do_quit2","dazuo");
        add_action("do_quit2","learn"); 
        add_action("do_quit2","xue");
        add_action("do_quit2","chat");
        add_action("do_quit2","respirate");
        add_action("do_quit2","suicide"); 
        add_action("do_quit2","suicide -f"); 
        add_action("do_quit2","persuade");
        add_action("do_quit2","practice");
        add_action("do_quit2","lian"); 
        add_action("do_quit2","study");
        add_action("do_quit2","du");
        add_action("do_quit2","teach");
        add_action("do_quit2","jiao");
}

int do_quit(string arg)
{
        if(arg=="roar") {
        write(this_player()->query("name")+"�����ĵķ�ʡ����ɣ�\n");
        return 1;
        }

        if(arg=="all") {
        write(this_player()->query("name")+"�����ĵķ�ʡ����ɣ�\n");
        return 1;
        }
        if(arg=="corpse") {
        write(this_player()->query("name")+"�����ĵķ�ʡ����ɣ�\n");
        return 1;
}  
}
int do_quit2(string arg)
{
        write(this_player()->query("name")+"�����ĵķ�ʡ����ɣ�\n");
        return 1;
}
