// modified by snowman.  ����Ƿ�busy�� fighting

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"���ľ�"NOR);
	set("long", @LONG
����һ��ǧ��ž�������������ʯ���ɵľ�̨����������������
�͵�һ����һ�ߵľ�Ե���������ʮ���ף�ˮ����Ư������Ҷ������
�Ӳݴ��������ߵ���ꤼ�Ҳ������ˣ���Ȼ�ܾ�û�����ˣ���ֵ���
���ߵ�ʯ���Ȼʮ�ֹ⻬��
LONG);
	set("exits", ([
		"west" : __DIR__"bzqn",
	]));

        set("resource/water",1); 
	set("outdoors", "������");
	set("coor/x",-380);
  set("coor/y",-270);
   set("coor/z",30);
   setup();
}
void init()
{
        add_action("do_tiao", "tiao");  
}

int do_tiao(string arg)
{
	object me=this_player();
	object weapon = me->query_temp("weapon");

        if ( !arg || (arg != "leaf") )
		return notify_fail("��Ҫ��ʲô��\n");
         
        if( me->is_busy() || me->is_fighting() ) return notify_fail("����æ���ء�\n");
        if (!weapon || weapon->query("skill_type") != "sword" )
		return notify_fail("��Ҫ���ְ���Ҷ��������\n");

        if ((int)me->query_skill("sword", 1) < 30 )
          return notify_fail("����ͷ�󺹵����˰��죬��һƬҳ��Ҳû���ţ����Ǹɴ������ðɡ�\n");

        if ((int)me->query_skill("sword", 1) >100 )
        return notify_fail("�㡰�ৡ������Ͱ����е���Ҷ�������˾��⡣\n");
    
	me->receive_damage("jingli", random(40));
        write("�㲻���ý�����Ҷ�������⣬��Ҷ��ˮƯ��Ưȥ����Խ��������µ���ʶ��\n");
         me->improve_skill("sword", me->query("int"));       
         return 1;
}                                     
