// Room: /d/dali/nj.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "ŭ��");
	set("long", @LONG
ŭ����Դ����ظ�ԭ���ƹ���ɽ��´�����β����������������������ˮ
�ӡ���������������ɽ�Ͳ�������֮���Ͽ���У�ʼ�ơ�ŭ������ŭ��������
ŭɽ�͸��蹱ɽ֮�䣬����ɽ�ڰζ�����ǧ�����ϣ�ɽ�������������
ˮ��̲�ߣ��С�һ̲��һ̲��һ̲��ʮ�ɡ���˵����ʮ�����ɡ�������Σ�£�
�С�ˮ�޲�ŭʯ��ɽ�����ɷ塱֮�ơ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
           "west" : __DIR__"futiao",
           "southup" : __DIR__"xueshan",
           "northeast" : "/d/tls/diancang",
	]));

	set("coor/x",-360);
  set("coor/y",-430);
   set("coor/z",-10);
   setup();
}
