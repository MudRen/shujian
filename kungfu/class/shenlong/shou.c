//Cracked by Roath
// shou toutuo ��ͷ��

inherit NPC;
// inherit F_MASTER;

#include <ansi.h>
#include <room.h>
#include "/d/REGIONS.h"
#include "/kungfu/class/shenlong/sg_ids.h"

#define SGDATA "/d/shenlong/data/"
#define SGCANGKU "/d/shenlong/cangku"

int auto_perform();

string ask_jiao();
string ask_wan();
string ask_exp();
string ask_task();
string ask_victim();
int ask_ob(string);

void create()
{
	set_name("��ͷ��", ({ "shou toutuo", "shou","toutuo" }));
//      set("nickname", "�䵱����");
	set("long",
		"�ְ����֣�ȫ�����������\n"
		"����ƫ��ʮ�ֻ��󣬳�����Ӷ��ǽ��С�\n"
		"������ټ���һ�𣬵��Ǹ���Ӳ�����Ĵ����һ�š�\n");
	set("gender", "����");
	set("age", 44);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jingli", 1200);
	set("max_jingli", 1200);
	set("jiali", 60);
	set("combat_exp", 300000);
	set("score", 50000);

	set_skill("force", 120);
	set_skill("dulong-dafa", 100);
	set_skill("dodge", 100);
	set_skill("lingshe-shenfa", 100);
	set_skill("strike", 120);
	set_skill("huagu-mianzhang", 120);
	set_skill("parry", 120);
	set_skill("hook", 120);
	set_skill("ruyi-gou", 120);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "ruyi-gou");
	map_skill("hook", "ruyi-gou");

	prepare_skill("strike", "huagu-mianzhang");

	create_family("������", 2, "����");

        set("chat_chance", 20);
        set("chat_msg_combat",({
                (:auto_perform:),
        }));

        set("inquiry", ([
                "������" : (:ask_jiao:),
                "��̥�׽���" : (:ask_wan:),
                "����" : (:ask_task:),
                "����"   : (:ask_exp:),
                "��λ" : (:ask_victim:),
                "�鰲ͨ" : "������������˵����",
                "����" : (: ask_ob, "hong" :),
                "����"   : "û��û�صġ�",
                "����" : (:ask_ob, "su":),
                "��ͷ��" : (: ask_ob, "pang" :),
                "½����" : (:ask_ob, "lu":),
                "½���" : (:ask_ob, "lu":),
                "�޸�����" : (:ask_ob, "wu":),
                "����ʹ" : (:ask_ob, "wu":),
                "��ѩͤ" : (:ask_ob, "xu":),
                "����ʹ" : (:ask_ob, "xu":),
                "���" : (:ask_ob, "yin":),
                "����ʹ" : (:ask_ob, "yin":),
                "�ŵ���" : (:ask_ob, "zhang":),
                "����ʹ" : (:ask_ob, "zhang":),
                "zhang" : (:ask_ob, "zhang":),
                "��־��" : (:ask_ob, "zhong":),
                "����ʹ" : (:ask_ob, "zhong":), 
                "������" : "�����������ݵĶ������򣬴������ڳ����㵽��",
        ]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/hook")->wield();
}

string ask_jiao()
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "�޳ܵ���ͽ���������ҹ�������";

        if( !me->query("sg/spy") )
                return "���Ǳ̵ֽ����ܣ���ʲô���ʵģ���";

        return "���ڽ��е����飬��ȥ����ͷ�Ӱɡ�";
}

string ask_wan()
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "�޳ܵ���ͽ���������ҹ�������";

        if( !me->query("sg/spy") )
                return "���Ǳ̵ֽ����ܣ���ʲô���ʵģ���";

        return "��̥�׽�������ͷ���Ƕ���";
}

string ask_exp()
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "�޳ܵ���ͽ���������ҹ�������";

        if( !me->query("sg/spy") )
                return "�㲻�ڱֽ̣����ͺδ�̸��";

        return "�Ҳ�̫������㻹��ȥ����ͷ�Ӱɡ�";
}

string ask_task()
{
        object me = this_player();

        if( me->query("sg/cured") )
                return "�޳ܵ���ͽ���������ҹ�������\n";

        if( !me->query("sg/spy") )
                return "���Ǳ̵ֽ����ܣ���ʲô���ʵģ���\n";

        return "��ר��ɱ��������ʹ����������ʦ����ͷ�ӡ�";
}

string ask_victim()
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "�޳ܵ���ͽ���������ҹ�������";

        if( !me->query("sg/spy") )
                return "�㲻�ڱֽ̣����ͺδ�̸��";

        return "��ֻ֪��������ʿ�ķ�λ������������ʹ�����������Ϣ��";       
}

int ask_ob(string id)
{
        object *obj, ob, place, cangku;

        if( !this_player()->query("sg/spy") ) { 
                say("���Ǳ̵ֽ����ܣ���ʲô���ʵģ���\n");
                return 1;
        }

        if( !(cangku = find_object(SGCANGKU)) )
                cangku = load_object(SGCANGKU);

        if( member_array(id, keys(ids)) == -1)
                return 0;

        obj = filter_array(children("/kungfu/class/shenlong/" + id + ".c"), (: clonep :));

        if( !sizeof(obj) ) {
                command("whisper " + this_player()->query("id") + " " + "̾��" + ids[id] + "����ɱ�ˣ�");
                return 1;
        }

        ob = obj[random(sizeof(obj))];
        place = environment(ob);

        command("whisper " + this_player()->query("id") + " " + ids[id] + "������" + region_names[explode(base_name(place), "/")[1]] + (string)place->query("short") + "��");
        return 1;
}

