//bao.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("��ϧ��", ({ "bao xiruo", "bao", "xiruo" }) );
	set("gender", "Ů��" );
	set("age", 25);
	set("long",
"����ļ��ã���Ȼ���е�ڣ����ǻ��ǿ������޵����Ķ��ˡ�\n");
	set("str", 10);
	set("dex", 10);
	set("con", 5);
	set("int", 5);
	set("per", 30);
	set("shen_type", 1);
	set_skill("unarmed", 5);
    
	set("combat_exp", 15000);
	set("max_qi", 100);
	set("max_jing", 100);
	set("max_neili", 0);
	set("eff_jingli",200);
	set("qi",100);
	set("jing",100);
	set("jingli",200);
	set("neili", 0);

  set("inquiry", ([
    "��Х��" : "�����ҷ�����֡�",
    "�" : "����һ�����˸���δ�����Ķ�Ůȡ�����֡�",
    "����" : "�����ҷ�����ֹ�Х��Ĺ��⡣",
    "��Ƽ" : "������ɩ��",

	]));

     setup();
	carry_object("/clone/armor/cloth.c")->wear();
	carry_object(ARMOR_D("shoes"))->wear();
} 



