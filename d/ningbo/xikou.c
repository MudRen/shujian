// xikou.c Ϫ��
// Modify By River@SJ 99.06
#include <ansi.h>
#include <wanted.h>

inherit ROOM;
void create()
{
        set("short", "Ϫ��");
        set("long", @LONG
��ӭ�����󺣷�������Ϫ�ڣ��������ԹŴ��������ұ���֮�أ���������
���뺣���ó�ף�����ͣ���ŵļ��Ҵ󷫴���Ϧ���������£������Ե÷�����
���������м��������������������ˣ�Ҳ������ǰѯ��һ�¾��ܹʹ�������
LONG);
	set("outdoors", "����");
	set("exits",([
		"west" : __DIR__"aywsi",
		"south" : __DIR__"dongqianhu",
	]));
	set("objects",([
		"/d/mingjiao/npc/shao"  :   1,
	]));       
	setup();
}

void init()
{
	if (is_wanted(this_player())) return;
	add_action("do_yell", "yell");
	add_action("do_enter", "enter");
}

int do_yell(string arg)
{
        object ob,me, obj;
        me = this_player();

        if (!arg) return 0;
        if (arg == "chuan"){
             message_vision("$N���ź�������һ���������ң���������\n", me);
             if(!me->query_temp("haichuan_paid")){
                 message_vision("�����ϵ�������$N������\n", me);
                 return 1;
             }
             if(query("boat_on_sea")) return notify_fail("�����ϵ�����˵�������������أ������ɡ�\n");
             if(!objectp(obj = present("shao gong", environment(me))) || !living(obj))
                       return notify_fail("����������ż���ȴû�˸����ٻ�һֻ����������\n");
             message_vision("�������ͷ������һֻ������˵��$N�������Ѿ����ˣ���ȥ(enter)�ɡ�\n\n", me);
             ob=new("/clone/misc/boat1");
             ob->set("boat_of", "/d/ningbo/xikou");
             ob->set_temp("stepw", 14);
             ob->set_temp("steps", 14);
             ob->move("/clone/misc/sea");
             set("boat_on_sea", 1);
             return 1;
        }
        else message_vision("$N���Ŵ󺣴��һ������" + arg + "��������\n", me);      
        return 1;
}

int do_enter()
{
        object me, sea, *inv;
        int i;
        me = this_player();
        
        if(!query("boat_on_sea")) return 0;
        if(!(sea = find_object("/clone/misc/sea")))
             sea = load_object("/clone/misc/sea");
        if(sea = find_object("/clone/misc/sea")){
             inv = all_inventory(sea);
             for(i= 0;i< sizeof(inv);i++){
                   if(inv[i]->query("boat_of") == base_name(this_object())){
                          message_vision("$N�����һ���ĵ��ϸߣ����¾ʹ����˷�����\n\n", me);
                          me->move(inv[i]);
                          message("vision",me->name()+"�����һ������������\n",environment(me), ({me}) );
                          return 1;
                   }
             }
        }
        else write("sea boat error, please call wizard. \n");
        return 1;
}