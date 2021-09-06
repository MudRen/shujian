//Cracked by Roath
// qinglong shi ����ʹ
// by aln 1 / 98

inherit F_UNIQUE;
inherit NPC;
// inherit F_MASTER;

#include <ansi.h>
#include <room.h>

#define SGDATA "/d/shenlong/data/"
#define SGCANGKU "/d/shenlong/cangku"
#define SGZHAO "/d/shenlong/obj/sg_mianzhao"

string ask_jiao();
string ask_wan();
string ask_exp();
string ask_task();
string ask_victim();
string ask_ob(string);

int is_suitable(object, object);
string assign_job(object);

/*
string* homes = ({
        "/d/city/guangchang",
        "/d/quanzhou/zhongxin",
        "/d/wudang/shanmen",
        "/d/shaolin/fzlou",
        "/d/shaolin/guangchang1",
        "/d/taishan/fengchan",
        "/d/taishan/yidao1",
        "/d/huashan/laojun",
        "/d/village/square",
        "/d/xingxiu/tianroad3",
        "/d/forest/bank3",
        "/d/emei/baoguomen",
        "/d/emei/xixiang",
        "/d/qilian/qilian",
        "/d/dali/wangfu1",
        "/d/xixia/square",
});
*/

void create()
{
	set_name("��ѩͤ", ({ "xu xueting","qinglong shi", "shi","xu" }));
	set("nickname", "����ʹ");
	set("long",
		"���ݺ��ӣ�Ŀ�⾼��������ȥʮ�ָ�����\n");
	set("gender", "����");
	set("age", 48);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 32);
	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jingli", 1200);
	set("max_jingli", 1800);
	set("jiali", 70);
	set("combat_exp", 460000);
	set("score", 50000);
	set("shen", -25000);

	set_skill("force", 150);
	set_skill("dulong-dafa", 120);
	set_skill("dodge", 140);
	set_skill("lingshe-shenfa", 130);
	set_skill("strike", 130);
	set_skill("huagu-mianzhang", 130);
	set_skill("parry", 130);
	set_skill("finger", 120);
        set_skill("club", 130);
        set_skill("weituo-gun", 130);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "weituo-gun");
        map_skill("club", "weituo-gun");

	prepare_skill("strike", "huagu-mianzhang");

	create_family("������", 2, "ʹ��");

        set("chat_chance", 20);
        set("chat_msg",({
                (:random_move:)
        }));

        set("inquiry", ([
                "������" : (:ask_jiao:),
                "��̥�׽���" : (:ask_wan:),
                "����"   : (:ask_exp:),
                "����" : (:ask_task:),
                "job" : (:ask_task:),
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
        ::create();

	carry_object("/clone/weapon/panguanbi")->wield();
	carry_object("/clone/misc/cloth")->wear();
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

string ask_victim()
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "�޳ܵ���ͽ���������ҹ�������";

        if( !me->query("sg/spy") )
                return "�㲻�ڱֽ̣����ͺδ�̸��";

        return "�Ҳ�̫������㻹��ȥ�ʺ���ʹ�ɡ�";
}

string ask_ob(string id)
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "�޳ܵ���ͽ���������ҹ�������";

        if( !me->query("sg/spy") )
                return "�㲻�ڱֽ̣����ͺδ�̸��";

        return "���ڽ��е����飬��ȥ����ͷ�Ӱɡ�";
}

string ask_task()
{
        object me = this_player();
        string str;

        if( me->query("sg/cured") )
                return "�޳ܵ���ͽ���������ҹ�������\n";

        if( !me->query("sg/spy") )
                return "���Ǳ̵ֽ����ܣ���ʲô���ʵģ���\n";

        if( (int)me->query("sg/exp") < 100 )
                return "��ƾ���ڽ��еı��֣�����ô�ܸ��������Σ�";

        if( !me->query("sgjob") ) {
                if( mapp(me->query("sg_ok")) ) {
                        me->delete("sg_ok");
                        command("thumb " + me->query("id"));
                }
                if( !(str = assign_job(me)) )
                        return "����û���ʺ���Ľ������´������ɡ�";
                return  str + "��";
        }

        if( time() > (int)me->query("sgjob/assigntime") + 3600 ) {
                me->delete("sgjob");
                command("nod " + me->query("id"));
                if( !(str = assign_job(me)) )
                        return "����û���ʺ���Ľ������´������ɡ�";
                return  str + "��";
        }

        return "����ȥ�ѵ�ǰ����������ˣ��������ҡ�";
}

private int is_suitable(object victim, object killer)
{
        mapping map;
        object room;

        if( !(room = find_object("/d/taishan/fengchan")) )
                room = load_object("/d/taishan/fengchan");

        if( !mapp(map = killer->query("sg_victim")) )
                map = ([]);

        if( victim->query("combat_exp") * 4 < killer->query("combat_exp") * 3
         || victim->query("combat_exp") * 4 > killer->query("combat_exp") * 5
         || victim->query("sg/spy")
         || victim->query("family/family_name") == "������"
         || victim->query("id") == room->query("winner")
         || victim == killer
         || member_array(victim->query("id"), values(map)) != -1
         || wizardp(victim) )
                return 0;

        return 1;
}

string assign_job(object me)
{
        object ob, victim;
        mapping map;
        string *times;
        mixed victim_list;

        if( !present("mianzhao", me) ) {
                ob = new(SGZHAO);
                ob->set("owner", me);
                ob->move(me);
                message_vision("$N����$nһ" + ob->query("unit") + ob->name() + "��\n", this_object(), me);
        }

        if( mapp(map = me->query("sg_victim")) ) {
                times = keys(map);
                for(int i = 0; i < sizeof(times); i++) {
                        if( time() > atoi(times[i]) + 259200 )
                                map_delete(map, times[i]);
                }
                me->set("sg_victim", map);
        }

        if( !(victim_list = filter_array(users(), "is_suitable", this_object(), me)) )
                return "";
        victim = victim_list[random(sizeof(victim_list))];

        me->set("sgjob/victim_name", victim->query("name"));
        me->set("sgjob/victim_id", victim->query("id"));
        me->set("sgjob/assigntime", time());

        log_file("test/ShenlongJob", sprintf("%s��%sʱ��ָ��ȥ׷ɱ%s\n", me->query("name"), ctime(time()), me->query("sgjob/victim_name")));

        return "��ȥ��" + me->query("sgjob/victim_name") + "(" + me->query("sgjob/victim_id")  + ")" + "ɱ��";
}

/*
int return_home(object home)
{
                // Are we at home already?
        if( !environment()
        ||      environment()==home )
                return 1;

        // Are we able to leave?
        if( !living(this_object())
        ||  is_fighting() || is_busy() ) return 0;

        // Leave for home now.
        message("vision", this_object()->name() + "����ææ���뿪�ˡ�\n",
                environment(), this_object());

        home = load_object(homes[random(sizeof(homes))]);
        if (home) return move(home);
        return 0;
}
*/
