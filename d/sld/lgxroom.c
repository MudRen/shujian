// lgxroom.c
// ½������
inherit ROOM;
void create()
{
	set("short","½������");
	set("long",@long
������������ɢ��½�����ļң������ı��Ϲ��˲����黭�����в�����ֵ
����֮���������֪�����˶Դ��ǻ����˴�����Ѫ���ŵ����ռ�����˶����
��֮����
long);
	set("exits",([
	    "north" : __DIR__"lgxws",
           "east" : __DIR__"lgxys",
                   "out" : __DIR__"kongdi",
]));
       set("objects",([
		__DIR__"npc/lgx" : 1,
]));
	set("coor/x",490);
  set("coor/y",410);
   set("coor/z",10);
   setup();
}
	    	
int valid_leave(object me, string dir)
{
	if (dir == "out")
	{
		me->delete_temp("yaozhong");
		me->delete_temp("makeyao");
	}
	return ::valid_leave(me, dir);
} 
