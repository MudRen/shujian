//songshu4.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֡��߸ߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ��
������գ��������ڵ�˿��Ҳ�ޡ�һ���ྻ����ʯС���������С������Ժ
����ǽ���Ժ��Ժ��վ������ɮ�����ܵ��ػ��š�
LONG
	);
        set("outdoor","shaolin");
	set("exits", ([
		   "west" : __DIR__ "songshu3",
                   "east" : __DIR__ "jieluyua",
          ]));
        set("objects",([
		
		__DIR__"npc/zjseng" : 1,
                __DIR__"npc/slseng" : 1
		
	]));
	set("coor/x",80);
  set("coor/y",290);
   set("coor/z",110);
   setup();
}

int valid_leave(object me, string dir)
{
	mapping fam;

        if (dir == "east"&&!wizardp(me))
	{
		if (me->query_condition("killer"))
			return notify_fail("ͨ������׼�������Ժ��\n");
		if( mapp(fam = me->query("family")) 
		&&  fam["family_name"] == "������"
		&&  fam["generation"] <= 37 )
			return ::valid_leave(me, dir);
		
		if( me->query("guilty") == 0 
		|| !userp(me))
			return notify_fail("ֻ��Ժ�ڴ���һ����������˵������δ����ɣ����ܽ������Ժ��\n");
	}

    return ::valid_leave(me, dir);
}
