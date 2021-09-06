// prince.c ��������
// by iceland

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��������", ({"zongzan wangzi","zongzan","prince","wangzi"}));
	set("long",@LONG
������ެ���������ӣ�δ������ެ������������Ũü���ۣ���ǿ��׳��
����������������ɫ�ر�Ľ�����б���۲���������´����š�
LONG
	);

        set("title", HIR "��ެ������" NOR);
	set("gender", "����");
	set("attitude", "heroism");

	set("age", 30);
	set("shen_type", -1);
	set("str", 26);
	set("int", 15);
	set("con", 25);
	set("dex", 22);
	set("max_qi", 1000);
	set("eff_jing", 400);
	set("max_jing",400);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("score", 5000);
	set("unique", 1);

	set_skill("force", 120);
	set_skill("longxiang-boruo", 120);
	set_skill("dodge", 120);
	set_skill("yuxue-dunxing", 120);
	set_skill("strike", 120);
	set_skill("huoyan-dao", 120);
	set_skill("parry", 35);
	set_skill("huanxi-chan", 120);
	set_skill("literate", 60);

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("strike", "huoyan-dao");
	map_skill("parry", "huoyan-dao");

	prepare_skill("strike", "huoyan-dao");

	setup();

        carry_object(ARMOR_D("pifeng"))->wear();
}