// Room: /dali/dangpu
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ������������ƽ���Ƶ����ֺŵ��̣���ȫ�����������ܴ�һ����
�ӣ�paizi)�߸߹���ǽ�ϣ���̨�����ŵ��̵��ϰ壬����һ�˴�ˮ�̴�������
�´������㡣
LONG
	);
	set("no_sleep_room",1);
        set("no_fight",1);
        set("no_clean_up", 0);

	set("item_desc", ([
		"paizi" : "��ƽ���ף��������ۡ�\n",
	]));
	set("objects", ([
		__DIR__"npc/shen" : 1,
             	__DIR__"npc/shengyiren" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"dongjie1",
	]));

	set("coor/x",-280);
  set("coor/y",-390);
   set("coor/z",-20);
   setup(); 
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/dangpu",1);
      }
}
