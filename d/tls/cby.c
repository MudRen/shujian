inherit ROOM;

void create()
{
        set("short", "�ȱ�Ժ");
        set("long",@LONG
����ɮ���ǵ㻯��ͽ�ĵط������ٽ���������������˴��ɱɱ
�����ӣ������˴��䷢Ϊɮ���������š�ǽ��һ�������������߸�
��һ���������飺�������������سɷ𡣴˴������Ǹ�������������
����Ʒ����
LONG);
        set("exits", ([
                "east" : __DIR__"bingqi",
		"west" : __DIR__"road4",
		"north" : __DIR__"wuping",
	]));    
        set("coor/x",-340);
  set("coor/y",-280);
   set("coor/z",30);
   setup();
}
