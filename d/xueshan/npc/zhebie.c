// zhebie.c �ܱ�

inherit NPC;
#include <ansi.h>
#include "cike.h";

void create()
{
	set_name("�ܱ�", ({ "zhe bie", "zhebie","zhe","bie"}));
	set("gender", "����");
        set("title",HIR"����Ӫǧ�� �����"NOR);
	set("age", 35);
	set("str", 25);
	set("dex", 30);
	set("long", "����ɫ΢�ڣ�һ˫ӥĿ�������񣬾���Ͷ���͸�Žý���\n���ļ������ڣ��ٷ����С�����Ϊ���������");
	set("max_qi",800);
	set("eff_jing",300);
	set("max_jing",300);
	set("combat_exp", 500000);
	set("shen_type", -1);
	set("attitude", "heroism");
	set("unique", 1);

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("dagger", 120);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 120);
	set_temp("apply/defense",120);
	set_temp("apply/armor", 120);
	set_temp("apply/damage", 120);

	setup();
    carry_object(BINGQI_D("dujiaotongren"))->wield();
	carry_object(ARMOR_D("bianfuxuejia"))->wear();
}

