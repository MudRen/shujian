inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long",@long
����һ��ͻ��ƽ�صľ�ʯ����Ϊ��ʯ������ʯ��������š�����������
���֣����ϰ��۴�����˵�Ƿ������ʩ��ʯ��������̫��ʯ���µĽ�ӡ����
ʯ���Ը��ӣ�����������ˮ�ݡ�
long);
set("outdoors", "suzhou");
set("objects",([
__DIR__"npc/ke" : 2,
]));
set("exits",([
"southup" : __DIR__"lingyansi",
"westdown" : __DIR__"shuiwa1",
"eastdown" : __DIR__"shuiwa",
"northdown" : __DIR__"yingxiaoting",
"southwest" : __DIR__"mubei",
]));
set("coor/x",130);
  set("coor/y",-300);
   set("coor/z",20);
   setup();
}
