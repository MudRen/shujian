// /d/mingjiao/bidao12.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
// Modify By Looklove@SJ 2001/1

#include <room.h>
inherit ROOM;
void create()
{ 
       set("short","�ص�");
       set("long", @LONG
�������ص��ľ�ͷ�����ܽ���ʯ�ڡ�ʯ�����м�����ʯ���䣬¶���ĵط�
�����Ǽ���ʯש(zhuan)���ϱ���һ��ر����ĵط���
LONG);    
       set("exits", ([
                "westup" : __DIR__"bidao11",
                "south" : __DIR__"bidao13",
       ]));             
       set("item_desc", ([
               "wall" : "ʯ�ڣ�����ʯ�ڣ����ܽ�Ϊʯ�ڡ�\n",
               "zhuan" : "ʯ����¶���ļ���ʯש��\n"
       ]));            
       setup();
}

void check_trigger()
{
        if((int)query("pull_trigger")==4){
           message("vision", "\n�������Ĵ�ʯ����ȡ���Ŀ�ʯש��¶����һ�����ڣ�ǡ��������һ�˽��롣\n", this_object());
           set("exits/enter", __DIR__"bidao14");
           delete("pull_trigger");
           remove_call_out("close_passage");
           call_out("close_passage", 15);
        }
}

void close_passage()
{
        if(!query("exits/enter")) return;
         message("vision", "ʯש��������������ڴ���ס�ˡ�\n", this_object());
         delete("exits/enter");
}

void init()
{
        add_action("do_pull",({"pull", "la"}));
}

int do_pull(string arg)
{
        if( !arg || arg=="" ) return 0;
        if( this_player()->is_busy() || this_player()->is_fighting())
                return notify_fail("����æ���أ�\n");
        if (this_player()->query_skill("force", 1 ) < 140) 
                return notify_fail("����������˿������������ƣ���������������ȷʵ�Ʋ�����\n");
        if (arg=="zhuan")
               return notify_fail("������һ����������ʯשһ�����о����ש�����������һ��\n");
        if (arg=="ʯש")
                return notify_fail("������һ��������������ʯשһ����������춯����\n");
        if (arg=="zhuan left")
                return notify_fail("������һ��������������ʯש����һ����������춯����\n");
        if (arg=="zhuan right")
                return notify_fail("������һ��������������ʯש����һ����������춯����\n");
        if (arg=="zhuan down"){
                message_vision("$N���˿�����ȡ����һ��ʯש��\n",this_player());
                add("pull_trigger", 1);
                this_player()->start_busy(1);
                check_trigger();
                return 1;
        }
        else{
             write("��Ҫ��ʲô��\n");
             return 1;
        }
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me,string dir)
{          
       object *inv = deep_inventory(me);
       object *obj;   
       if( me->query("combat_exp") < 350000 && dir == "enter")
            return notify_fail("�㲻֪��������ʲô���������Ӳ����ջ��������Ĳ��ӡ�\n");  
       obj = filter_array(inv,(:get_object:));
       if( sizeof(obj) && dir =="enter")
         return notify_fail ("�����صأ�������˽����ˣ�\n");
       return ::valid_leave(me, dir);
}
