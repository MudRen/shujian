// wu-santong.c ����ͨ
// by shang 97/6

inherit NPC;

void create()
{
        set_name("����ͨ", ({ "wu santong", "wu" }) );
	set("gender", "����" );
        set("age", 45);
	set("long", "������ͷ�ҷ�������Ҳ��������������һ��,\n" "�뷢�͹��ںڣ���˵��Ͳ��󣬿��������������ݣ�ȴ���߰�ʮ�����̣�\n" "������ֱ׺�����й�����Ӥ�����õĽ���Χ�ѣ�Χ������������è�˵�ͼ����Ȼ�¾����á�\n");
	set("attitude", "friendly");
        set("str", 30);
        set("dex", 24);
        set("con", 30);
        set("int", 20);
        set("shen_type", 1);

        set_skill("parry", 130);
        set_skill("dodge", 130);
        set_skill("force", 130);
        set_skill("literate", 100);
        set_skill("yiyang-zhi", 130);
        set_skill("finger", 130);
        set_skill("qiantian-yiyang", 130);
        set_skill("tianlong-xiang", 130);

        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "yiyang-zhi");
        map_skill("force", "qiantian-yiyang");
        map_skill("finger","yiyang-zhi");
        prepare_skill("finger","yiyang-zhi");

        set("jiali", 60);

        set("combat_exp", 500000);

        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("eff_jingli", 1500);

        set("inquiry", ([
		"�����" : "���䣬�����常Ҳ�����ˣ�",
		"½չԪ" : "���úã����úã�ֻ��ϧ�Ҳ�������ȡ��������",
		"�����" : "�����Ҵ���ӡ�",
		"������" : "�����Ҷ����ӡ�",
		"������" : "�������Ÿ�ʲô��",
	]));
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
}
