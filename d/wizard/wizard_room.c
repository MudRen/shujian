// Room: /d/wizard/wizard_room.c

inherit ROOM;
#include <ansi.h>
#include <mudlib.h>

string area_mulu();

void create()
{
	set("short", "��ʦ��Ϣ��");
	set("long",
"�������" + CHINESE_MUD_NAME +"��ʦ����Ϣ���ڣ����ˢ��������ǽ���ϵ�\n"
"������"HIC"һ��Ԫ��Ʊ"NOR"�����ӵ����������һ��"HIY"������"NOR"���������һ������\n"
"��ʦ���Բ�(board)��������û�����ӣ���ʦֻ��վ�ŷ����ˡ�\n"
HIW"��ʦ����������Ŀ¼(mulu)\n"NOR
);
	set("exits", ([
      		"up" : __DIR__"zoulang",
      		"enter" : "/adm/etc/admin_room",
	  	"down" : __DIR__"guest_room",
		"east" : __DIR__"wizard_meet"
	]));
	set("item_desc",([
		"mulu" : (: area_mulu :),
        ]));

	set("no_save", 1);
	set("no_fight", 1);
	set("incity",1);
	setup();
	call_other("/clone/board/wiz_b", "???");
}

void init()
{
	object ob = this_player();

  	if (userp(ob) && !wiz_level(ob)) {
		ob->move("/d/wizard/guest_room");
		message_vision("$N����ʦ��Ϣ�����ص�ˤ��������\n", ob);
		ob->unconcious();
	}

}

string area_mulu()
{
	write("\n
�����ɰ������ط��䣬ͳһʹ�õ�������������������
���磬  murong�� Ӧ���� /area/jiangnan/yanziwu
	mingjiao Ӧ���� /area/kunlun/guangmingding
	kunlun�� Ӧ���� /area/kunlun/xxxshan...

���ڻ��� area Ϊ��

	����(kunlun)��	����ɽ������
			�������̣������ɣ�ѩɽ��(����)�����ڵȡ�
	����(xiyu)��	�Ӽ����ؿ�ʼ��������
			�������޺������磬����ɽ����ɽ�������صȡ�
	����(xinan)��	�������ϣ��ƹ����ء�
			������ü�����������£���ǣ��置������ɽ����ָɽ���ɶ��ȡ�
	����(dongbei)��	ɽ��������������
			����¹��ɽ���Ÿ����ȡ�");

	return "
	��ԭ(caoyuan)��	����ͱ���
			�����ؽ������ģ��ɹŵȡ�
	����(jiangnan)���������ϣ������ƹ󴨵���������
			�������ݣ����ˣ����ݣ�Ȫ�ݣ���ɽ����̨ɽ�������룬÷ׯ����ػ��ܶ棬
			���ݣ���ɽ������ׯ���ȡ�
	����(jiangbei)�������Ա����ƺ����ϵ��м�ش���
			����̩ɽ����ɽ���䵱ɽ����������ɽ�����ɽ�����ݣ�����������ɽ������ȡ�
	�ӱ�(hebei)��	�ƺ��Ա���ֱ��ɽ���ؼ����������
			��������������ɽ����ɽ����̨ɽ��ɽ���أ������ŵȡ�
	����(haiwai)��	���к������Լ������л����������
			����Ī˹�ƣ���˹����ɣ�����𵺣��һ��������͵��ȡ�
	����(special)��	�����������򣬲���map������Χ�ڡ�
			������������ʦ�ش�����̨�ȡ�

        ����Ŀ¼���� test site ����������ʦ�밴���Ը�������ɸĶ�����Ŀ¼Ϊ /oldd��\n";
}
int valid_enter(int t)
{
	return 0;
}

