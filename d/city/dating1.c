//�¿�ǰ�������������䳡��
//modified by campsun 2003/09/26
inherit ROOM;
void create()
{
        set("short","�ĳ�����");
        set("long", @LONG
��һ�߽��ⷿ�䣬ֻ���������ᣬ��������������֮����˵�������ö�
�����������Ѿ����������ˣ�����һ��Ĵ�磬���ھ۾�����������ӣ�̧
ͷһ�����ң�����һ�顣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
         "east" : __DIR__"duchang",
          "west" : __DIR__"cp_room",
         "north" : __DIR__"duchang4",
               "down" : __DIR__"dixiashi",
  
]));
        set("item_desc", ([
                "sign": @TEXT


���ӵĶķ���

�����������ࣾ����������

���ࣺ����������������������
������          ��С    ������������    һ��һ
����            �Ĵ�    ��������������  һ��һ
������          ��Χ��  ����������ͬ�㣩һ����ʮ��
��������        �ĵ���                  һ���

���ӣ�
��������������
����ʮ����С��

TEXT
        ]) );
        set("no_fight",1);
        set("no_sleep",1);
        set("objects", ([
        __DIR__"npc/pingwei" : 1,
                        ]) );
        set("coor/x",80);
  set("coor/y",-20);
   set("coor/z",0);
   setup();
}
void init()
{
object me;
me = this_player();
if( me->query("gamble/amount")) {
me->delete("gamble/amount");
me->decrease_skill("betting",1);
}

        add_action("action", ({
                   "dazuo",
                   "du",
                   "exercise",
                   "lian",
                   "practice",
                   "respirate",
                   "study",
                   "tuna",
                   															//��ֹ��Ҵ�ƽ�����ﰵ��ĳ��ϰ�
        }));
        add_action("ansuan",({"ansuan"}));
}

int action()
{
        write("���޷���������������\n");
        return 1;
}
int ansuan()
{
	string userip;
	userip = query_ip_number(this_player());
	write(userip+"\n");
	write("���밵��˭������ɲ��Ǵ�ܵĵط���\n");
	return 1;

}
int valid_leave(object me, string dir)
{
	if (userp(me)) 
		if( "/d/city/dixiashi"->checkSameIp(me) && dir == "down")
			return notify_fail("��ʹ���뼷�����¶ĳ�������̫���ˣ������������ȥ��\n");
	if ( !me->query_temp("dxdc/enter") && dir == "down" )
		return notify_fail("ƽ������������ǰһ�ᣬЦ������Ǹ�úܣ����治��ӭ���ͣ�\n");
	if ( (int)me->query_condition("killer") && dir == "down" )											//��ֹɱ�˷�������±��䳡
		return notify_fail("ƽ��ǰ����ϸ�Ĵ�������һ�飺���ǳ�ͨ͢����Ҫ���ɣ�����ɲ���ӭ�㡣\n");
		
	return ::valid_leave(me, dir);
}
