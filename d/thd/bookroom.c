// Room: /u/jpei/thd/bookroom.c
// ���ӵõ�jiugong tu���Ѷ� Modified by Numa 19990921

inherit ROOM;

void create()
{
        set("short", "�鷿");
        set("long", @LONG
�����ǻ�ҩʦ����ĵط�������������һ����Ⱦ��һ�Ź��ⰻȻ���鰸��
�ڷ������У����ϰ��ż��������˵���װ�鼮��
LONG
        );

        set("exits", ([
                "west" : __DIR__"shilu",
        ]));

        set("item_desc", ([
                "�鰸" : "һ�Ź��ⰻȻ���鰸������ɢ�ҵķ��ż����顣\n",
                "shuan" : "һ�Ź��ⰻȻ���鰸������ɢ�ҵķ��ż����顣\n",
        ]));

        setup();
}

void init()
{
        object me = this_player();
  	
  	if (me->query_temp("thd/tupu"))
        {
                add_action("do_fan","fan");
                add_action("do_fan","zhao");
                return;
        }
}

int do_fan(string arg)
{
        object me = this_player();
 	mapping fam;
        object ob;
        
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        
        if (!(fam = me->query("family")) 
           || fam["family_name"] != "�һ���")
        	return notify_fail(RANK_D->query_respect(me) + "���Ǳ��ɵ��ӣ���������Ϲ��ʲô��\n");
        
        if (!arg)
                return notify_fail("ʲô��\n");
	
	if (arg=="shuan" || arg == "�鰸")
	{
        	ob = unew(__DIR__"obj/tupu");
                
		if(!clonep(ob))
                	return notify_fail("�������ˣ��Ź�����ͼ���Ѿ����������ˡ�\n");
        	if(clonep(ob) && ob->violate_unique()){
           		destruct(ob);
                	return notify_fail("�������ˣ��Ź�����ͼ���Ѿ����������ˡ�\n");
                }
                write("����ϸ�ķ��˷��鰸���ҵ���һ���������Ű��Ե���!\n");
                write("�������������æ����������\n");
                ob->move(me);
                me->delete_temp("thd/tupu");
                return 1;
        }
}
