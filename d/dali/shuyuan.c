// Room: /dali/shuyuan.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
��������Ժ�Ľ��ã�����������һ����Ⱦ��һλׯ���������������̫ʦ
���Ͻ�ѧ��������������������ѧ��ѧ���ǡ�һ�Ź��ⰻȻ���鰸����������
��ǰ�棬���ϰ��ż�����������װ�鼮�������ڶ��������ʯ�̣������Ժ��
ʷ���ƾá�ֵ��һ�����Ƕ�ڽ���ǰ��ڵ�ѧ��(xuegui)��
LONG
	);

	set("exits", ([
           "west" : __DIR__"nanjie5",
	]));

	set("item_desc", ([
		"xuegui" : "�ս����������տ���Ŀ��ҳ��"  
			"\nͨ��ʱ�������ζ�����ʫ����" 
			"\n���������ʣ���ΰ�ʱ���ꡣ"
			"\nҹ���Խ���������Ҫ������\n",
	]));
	
	set("objects", ([
            __DIR__"npc/zhu": 1,
	]));

	set("coor/x",-280);
  set("coor/y",-460);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/shuyuan",1);
      }
}

int valid_leave(object me, string dir)
{
	me->set_temp("mark/literate", 0);
	return 1;
}
