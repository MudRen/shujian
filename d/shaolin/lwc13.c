//lwc13.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��Ĳ�
̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬��ʮ����ɮ��������ϰ�似���䳡��
һ����һ�������õ�÷��׮���������������һ���䳡��
LONG
	);

	set("exits", ([
		"east" : __DIR__"lwc12",
		"south" : __DIR__"lwc15",
                "west" : __DIR__"lwc14",
		]));
        set("objects",([
		__DIR__"obj/zhuang" : 1,
	]));

        
       set("item_desc", ([
             "zhuang" : "����һ�������Ƴɵ�ľ׮����һ�����磬״��÷�����С�\n",
       ]));
	set("outdoors", "shaolin");
	set("coor/x",90);
  set("coor/y",280);
   set("coor/z",110);
   setup();

}
/*
  void init()
   {
     add_action("do_jump","jump");
   }

  int do_jump(string arg)
     {
      object me;
      me = this_player();
      if(!living(this_player()) || arg!="zhuang")
       return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
      if((int)me->query_skill("dodge",1)>30) 
        return notify_fail("����÷��׮�ϲ�ͣ�Ĵ�����ȥ�������޷�������Ṧ��\n");
      if((int)me->query("jingli")<30){
           me->receive_damage("jingli",10);
           write("�����һ�����ȣ���÷��׮��������ȥ\n");
           me->unconcious();
		return 1;
	}
       me->receive_damage("jingli", random(35));
        write("����÷��׮�ϲ�ͣ�Ĵ�����ȥ���Ի����Ṧ��������\n");
message_vision("$N����һԾ����÷��׮����׮�ϻ�����ȥ��\n", me);  
                        me->improve_skill("dodge", me->query("int"));       
         return 1;         
}
*/
