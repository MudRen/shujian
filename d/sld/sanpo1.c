// sanpo1.c
// ɽ��1
inherit ROOM;

int do_hit(string arg);

void create()
{
	set("short","ɽ��");
	set("long",@long
������һ�鲻С��ƽ�£�ɽ·��������ת�˸���������������졣��
ɽ�µ�������һ��ʯ������������ֻʯ�ʣ����������Ǵֲڣ�ֻ��������
�ؿ����ö��ѡ�
long);
	set("exits",([
	    "eastup" : __DIR__"sanroad5",
          "down" : __DIR__"sanroad2",
          "north" : __DIR__"sanroad6",
]));
	set("item_desc",([
        "ʯ��" : "����������౻����(hit)������ӡ����\n",
]));
	set("outdoors", "������");
        set("coor/x",490);
  set("coor/y",420);
   set("coor/z",30);
   setup();
}

void init()
{
	add_action("do_hit","hit");
}	    	

int do_hit(string arg)
{
	object weapon;
	object me=this_player();
        int lev;

	if(!arg || arg=="" || arg==" " || arg!="ʯ��")
		return 0;
	if(me->query("jingli")<50)
	{
		tell_object(me,"������̫ƣ���ˣ�����Ϣһ�°ɡ�\n");
		return 1;
	}
	weapon = me->query_temp("weapon");
	if (!weapon || weapon->query("skill_type") != "whip")
	{
		tell_object(me,"��ݺݵ��Ļ���һ��ʯ������������ҳ���\n");
                me->add("jingli",-50);
		return 1;
	}
	lev=me->query_skill("whip", 1);
	if(lev<50 || lev>=100)
	{
		tell_object(me,"��ݺݵ��Ļ���һ��ʯ������������ҳ���\n");
                me->add("jingli",-50);
		return 1;
	}
	if( (string)SKILL_D("whip")->type()=="martial" &&
          lev * lev * lev / 10 > (int)me->query("combat_exp") ) 
        {
		tell_object(me,"��ݺݵ��Ļ���һ��ʯ������������ҳ���\n");
                me->add("jingli",-50);
		return 1;           
        } 
	if( !SKILL_D("whip")->valid_learn(me) )
	{
		tell_object(me,"��ݺݵ��Ļ���һ��ʯ������������ҳ���\n");
                me->add("jingli",-50);
		return 1;           
        } 
	tell_object(me,"��ݺݵ��Ļ���һ��ʯ������������ҳ���\n");
        me->add("jingli",-50);
	me->improve_skill("whip",lev/5+1,0);
	return 1;
}