//Cracked by Roath
// pangtoutuo ��ͷ��
// by ALN 10 / 97
// by ALN 12 / 97
// by ALN  1 / 98

inherit F_UNIQUE;
inherit NPC;

#include <ansi.h>
#include <room.h>

#define PANGHOME "/d/city/zuixianlou2"
#define SGCANGKU "/d/shenlong/cangku"
#define SGZHAO   "/d/shenlong/obj/sg_mianzhao"
#define SGJOBS   "/d/shenlong/sgjob/sgjob"

int auto_perform();
int random_walk();

int ask_jiao();
string ask_task();
string ask_wan();
string ask_exp();

int is_other(object, object);
int is_suitable(object, object);
int is_candidate(object, object);

string assign_job(object);
void apply_gift(object, int);

void gototalk(object);
void set_pang(object, string);
void del_busyfor();

string *homes = ({
        "/d/city/zuixianlou2",
        "/d/city/wumiao",
        "/d/city/kedian",
        "/d/city/duchang",
        "/d/city/biaoju",
        "/d/city/qianzhuang",
        "/d/city/yaopu",
        "/d/city/jujinge",
        "/d/city/lichunyuan",
        "/d/city/chaguan",
});

string *meetplaces = ({
        "/d/city/dongjiao2",
        "/d/city/xijiao2",
        "/d/city/beijiao2",
        "/d/city/nanjiao2",
});

mapping nondirs = ([
        "/d/city/dongdajie3": "east",
        "/d/city/nandajie3" : "south",
        "/d/city/xidajie2"  : "west",
        "/d/city/beidajie2" : "north",
]);

string *shaolinbooks = ({
        "�޺�ȭ��",
        "�������ַ�",
        "�����Ʒ�",
        "�ն��ȷ�",
        "��ħ����",
        "��Ħ����",
        "����ǧҶ���ַ�",
        "����ȭ��",
        "�޳��ȷ�",
        "�ȱ�����",
        "���޵���",
        "�������",
        "ɢ���Ʒ�",
        "�黨ָ��",
        "Τ�ӹ���",
        "ӥצ����",
        "��צ����",
        "һָ����",
});


void create()
{
	set_name("��ͷ��",({"pang toutuo","pang","toutuo"}));
	set("long",
		"�����ߣ��ݵó��棬����Ƥ����ͷ��˫Ŀ���ݣ�\n"
		"������罩ʬһ�㳤�����磬ͷ��һ��ͭ����ס�˳�����\n"
		"���ϴ�һ�����ۣ�������������ǹ����¼��ϡ�\n");
	set("gender","����");
	set("age",41);
	set("attitude","peaceful");
	set("shen_type",-1);
	set("str",28);
	set("int",28);
	set("con",28);
	set("dex",30);
	set("max_qi",1000);
	set("max_jing",1000);
	set("neili",1500);
	set("max_neili",1500);
	set("jingli",1200);
	set("max_jingli",1500);
	set("jiali", 100);
	set("combat_exp", 600000);
	set("score",60000);

	set_skill("force", 150);
	set_skill("dulong-dafa", 150);
	set_skill("dodge", 150);
	set_skill("lingshe-shenfa", 150);
	set_skill("strike", 150);
	set_skill("huagu-mianzhang", 150);
	set_skill("parry", 150);
	set_skill("blade", 150);
        set_skill("xiuluo-dao", 150);

        set_temp("apply/attack", 20);
        set_temp("apply/damage", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 50);

	map_skill("force","dulong-dafa");
	map_skill("dodge","lingshe-shenfa");
	map_skill("strike","huagu-mianzhang");
        map_skill("blade", "xiuluo-dao");
	map_skill("parry","xiuluo-dao");

	prepare_skill("strike","huagu-mianzhang");

	create_family("������", 2, "����");

        set("chat_msg_combat",({
                (:auto_perform:),
        }));

        set("stay_chance",1);
        set("no_clean_up",1);
        set("chat_chance", 50);
        set("chat_msg",({
		(: random_walk :)
	}));

        set("amount", 5 + random(5));

	setup();
        ::create();

        set("inquiry",([
                  "������" : (:ask_jiao:),
                  "jiao" : (:ask_jiao:),
                  "�鰲ͨ" : "������������˵����",
                  "�����" : "������ɸ������������룬�������Ŀ��磬�����ķ���",
                  "��̥�׽���" : (:ask_wan:),
                  "Ч��"   : (:ask_task:),
                  "task" : (:ask_task:),
                  "job"  : (:ask_task:),
                  "����"   : (:ask_task:),
                  "����"   : (:ask_exp:),
                  "point" : (:ask_exp:),
                  "��ͷ��" : "�����ˣ��۸���������⸱���ߡ�",
                  "������" : "�����������ݵĶ������򣬴������ڳ����㵽��",
	]));

	carry_object("/d/shenlong/obj/dahuandao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object me = this_player();
        string room, myid;

        ::init();

        if( !living(this_object()) || !interactive(me) 
         || !living(me) || is_fighting(me)
         || !filter_array(all_inventory(environment()), "is_other", this_object(), me) )
                return;

        if( me->query("sg/spy") )
                tell_object(me, "��ͷ�ӳ������ص�Ц��һЦ��\n");

        myid = me->query("id");
        if( me->query_temp("pang/a") && query_temp("busyfor") == myid 
        &&  member_array(base_name(environment()), meetplaces) != -1 ) {
                if( me->query("family/family_name") != "������" && !me->query("sg/spy") && !me->query("sg/cured") ) {
                        command("welcome " + myid);
                        say("��ͷ��˵�����������˱�̥�׽���󣬲�������������̡�\n");
		} else {
                        command("addoil " + myid);
                        say("��ͷ��˵�����н����ĺ鸣��������Խ��Խ�����ˡ�\n");
                }

                return set_pang(me, "c");
        }

        if( me->query_temp("pang/b") && query_temp("busyfor") == myid ) 
                return gototalk(me);
}

int ask_jiao()
{
        object cangku, victim, obj, me = this_player();
        object ob = this_object();
        mixed victim_list;
        string dayphases, myid;
        int myexp;

        if( me->query("sg/cured") ) {
                say("��ͷ�Ӵ�ŭ�����޳ܵ���ͽ���������ҹ�������\n");
                return 1;
        }

        if( !(cangku = find_object(SGCANGKU)) )
                cangku = load_object(SGCANGKU);

        if( is_fighting() || is_busy() 
        || (stringp(query_temp("busyfor")) && (string)query_temp("busyfor") != myid) ) {
                command("say ��û������æ�ţ�");
                return 1;
        }

        if( query("eff_qi") * 10 < query("max_qi") * 4 ) {
                command("say �������ˣ����¿첻���ˡ���һ��Ҫ���ұ��𡣡���");
                return 1;
        }

        myid = me->query("id");
        myexp = (int)me->query("combat_exp");

        if( !me->query("sg/spy") && !me->query("sg_ok/join") ) {
                if( myexp < 10000 ) {
                        command("say " + RANK_D->query_respect(me) + "�����ڽ����϶�켸��ɡ�");
                        return 1;
                } else if( myexp > 100000 ) {
                        command("say " + RANK_D->query_rude(me) + "Ī���������������ѵף�");
                        return 1;
                }

                if( time() > (int)me->query("sgjob_join/assigntime") + 86400 ) {
                        if( !sizeof(victim_list = filter_array(users(), "is_suitable", this_object(), me)) ) {
                                command("whisper " + myid + " " + "����ܲ��ɣ����´������ɡ�");
                                return 1;
                        }

                        if( !present("mianzhao", me) ) {
                                obj = new(SGZHAO);
                                obj->set("owner", me);
                                obj->move(me);
                        }

                        message_vision("$N����$nһ" + obj->query("unit") + obj->name() + "��\n", this_object(), me);

                        victim = victim_list[random(sizeof(victim_list))];

                        me->set("sgjob_join/victim_name", victim->query("name"));
                        me->set("sgjob_join/victim_id", victim->query("id"));
                        me->set("sgjob_join/assigntime", time());

                        log_file("test/ShenlongJointask", sprintf("%s��%sʱ��ָ��ȥ׷ɱ%s\n", me->query("name"), ctime(time()), me->query("sgjob_join/victim_name")));
                        command("whisper " + myid + " " + "��ȥ��" + me->query("sgjob_join/victim_name") + "(" + me->query("sgjob_join/victim_id") + ")" + "ɱ�ˣ��Ҳ���������̡�");
                        return 1;
                }

                command("whisper " + myid + " " + "û��Ͷ��״������ô��������ĳ��⣿");
                return 1;
        }

        set_temp("busyfor", myid);

        if( !sizeof(filter_array(all_inventory(environment()), "is_other", this_object(), me))  )
                gototalk(me);
        else {
                tell_object(me, "��ͷ������Ŭ��Ŭ�졣\n");
                set_pang(me, "b");
                return random_move();
	}

        return 1;
}

string ask_wan()
{
        object cangku, me = this_player();
        string str, v_id;
        mapping pkjob;
        int exp;

        if( me->query("sg/cured") )
                return "�޳ܵ���ͽ���������ҹ�������\n";

        if( !me->query_temp("pang/c") )
                return "����ҩ��Ҳ�ԣ���Ϲ����û���ҳ�����ͷ�ӣ�\n";
        me->delete_temp("pang");

        if( !me->query("sg/spy") ) {
                if( !me->query("sg_ok/join") )
                return "û��Ͷ��״������ô��������ĳ��⣿";

                command("touch " + me->query("id"));
                me->delete("sg_ok");
                me->set("sg/spy", 1);
                me->set("sg/joinage", (int)me->query("age"));
                log_file("test/ShenlongJoin", sprintf("%s��%sʱ����������\n", me->query("name"), ctime(time())));
                message_vision("��ͷ�Ӵ��´����ͳ�һ����̥�׽���������$N���������\n\n", me);
                call_out("apply_yj", 1, me);
                return "������������һ�����������ܽ��ڣ����ְ�����Ϊ�������������������ǣ�";
        }

        exp = (int)me->query("combat_exp");
        if( (int)me->query("sg/exp") < exp / 200 && exp > 100000 )
                return "��������Ӧ���ĺ�������������̫���ˣ��������µ��׽��衣";

        if( !mapp(me->query("sgjob")) && !mapp(me->query("sg_ok")) ) {
                if( !(str = assign_job(me)) )
                        return "���������Ա�̥�׽��裬ֻ��������û���ʺ���Ľ������´������ɡ�";
                else    return str + "��Ȼ���Ҳ��ܸ���һ����̥�׽��衣";
        }

        if( mapp(me->query("sg_ok")) ) {
                me->delete("sg_ok");
                command("nod " + me->query("id"));
                message_vision("��ͷ�Ӵ��´����ͳ�һ����̥�׽���������$N���������\n\n", me);
                call_out("apply_yj", 1, me);
                return "�ɵò���������һ����̥�׽��裡";
        }

        command("slap " + me->query("id"));

        if( (int)me->query("sg/exp") > 0 && time() > me->query("sgjob/assigntime") + 1800 ) { 
                me->delete("sgjob");
                me->add("sg/failure", 1);
                me->add("sg/exp", -1);
                if( (int)me->query("sg/exp") < 0 ) me->set("sg/exp", 0);
                say("��ͷ�Ӵ�ŭ���������������ң�\n");
                if( !(str = assign_job(me)) )
                        return "���������Ա�̥�׽��裬ֻ��������û���ʺ���Ľ������´������ɡ�";
                else    return "�ٸ���һ�λ��ᣬ" + str + "��Ȼ���Ҳ��ܸ���һ����̥�׽��衣";
        }

        return "������ȥ��һ�ԣ���";
}

string ask_task()
{
        object cangku, me = this_player();
        string str, v_id, *v_list;
        mapping pkjob;
        int punish, exp;

        if( me->query("sg/cured") )
                return "�޳ܵ���ͽ���������ҹ�������";

        if( !me->query("sg/spy") )
                return "���Ǳ̵ֽ����ܣ���ʲô���ʵģ���";

        if( !me->query_temp("pang/c") )
                return "��ʲô�ʣ�Ҳ������ʱ��ص㣡���������̴�����ô�ã�";
        me->delete_temp("pang");

        exp = (int)me->query("combat_exp");
        if( (int)me->query("sg/exp") < exp / 200 && exp > 100000 )
                return "��������Ӧ���ĺ�������������̫���ˣ�����ȥ����ʹ�Ƕ���һ���ɡ�";
                 
        if( !me->query("sgjob") ) {
                if( mapp(me->query("sg_ok")) ) {
                        me->delete("sg_ok");
                        command("thumb " + me->query("id"));
                }
                if( !(str = assign_job(me)) )
                        return "����û���ʺ���Ľ������´������ɡ�";
                return  str + "��";
        }

        command("slap " + me->query("id"));

        if( (int)me->query("sg/exp") > 5 && time() < me->query("sgjob/assigntime") + 1800 ) {
                punish = 3 + random(6);
                me->add("sg/failure", punish);
                me->add("sg/exp", -punish);
                if( (int)me->query("sg/exp") < 0 ) me->set("sg/exp", 0);
                say("����ǧ�գ��ñ�һʱ���������ĵķ���" + chinese_number(punish) + "�����͵㣡\n");

                me->delete("sgjob");
                if( !(str = assign_job(me)) )
                        return "����û���ʺ���Ľ������´������ɡ�";
                return  str + "��";
        }

        if( time() >= me->query("sgjob/assigntime") + 1800 ) { 
                me->delete("sgjob");
                me->add("sg/failure", 1);
                me->add("sg/exp", -1);
                if( (int)me->query("sg/exp") < 0 ) me->set("sg/exp", 0);
                say("��ͷ�Ӵ�ŭ���������������ң�\n");

                if( !(str = assign_job(me)) )
                        return "����û���ʺ���Ľ������´������ɡ�";
                return  str + "��";
        }

        return "������ȥ��һ�ԣ���";
}

string ask_exp()
{
        object me = this_player();
        if( me->query("sg/cured") )
                return "�޳ܵ���ͽ���������ҹ�������\n";

        if( !me->query("sg/spy") )
                return "���Ǳ̵ֽ����ܣ���ʲô���ʵģ���\n";

        if( !me->query_temp("pang/c") )
                return "��ʲô�ʣ�Ҳ������ʱ��ص㣡���������̴�����ô�ã�\n";
//      me->delete_temp("pang");

        command("thumb " + me->query("id"));
        return RANK_D->query_respect(me) + "�Ϳ๦�ߣ����ڹ��Ͳ��ϸ������" + chinese_number((int)me->query("sg/exp")) + "�㡣";
}

int random_walk()
{
        mapping exits, doors;
        string *dirs, dir, file;

        if( !objectp(environment()) 
        || !mapp(exits = environment()->query("exits")) 
        || is_fighting() || is_busy()
        || query("jingli") < query("max_jingli") / 2 ) return 0;

        file = base_name(environment());
        if( strsrch(file, "/d/city/") != 0 ) {
                message("vision", name() + "����ææ���뿪�ˡ�\n",
                environment(), this_object());
                move(homes[random(sizeof(homes))]);
                message("vision", name() + "���˹�����\n",
                environment(), this_object());
        }

        dirs = keys(exits);
        if( mapp(doors = environment()->query_doors()) ) {
                dirs += keys(doors);
        }

        if( member_array(file, keys(nondirs)) != -1 ) {
                say("��ͷ��ҡ��ҡͷ��˵������������뿪��������������磿\n");
	        dirs -= ({nondirs[file]});
	}

        if( sizeof(dirs) == 0 ) return 0;

        dir = dirs[random(sizeof(dirs))];
        if ( mapp(doors) && !undefinedp(doors[dir])
          && (doors[dir]["status"] & DOOR_CLOSED) )
                command("open " + dir);
        command("go " + dir);
        return 1;
}

int accept_object(object who, object ob)
{
        mapping sgjob;
        string chname = "", name;
        int bonus;

        if( who->query("sg/cured") )
                return notify_fail("��ͷ�Ӵ�ŭ�����޳ܵ���ͽ���������ҹ�������\n");

        if( !who->query("sg/spy") )
                return notify_fail("��ͷ��˵����" + RANK_D->query_respect(ob) + "��ֽ������������Ҳ�������Ķ�����\n");

        if( !(sgjob = who->query("sgjob")) )
                return notify_fail("��ͷ��˵�����ⲻ������Ҫ�ġ�\n");

        name = ob->name();
        for(int i = 0; i < strlen(name); i++)
                if(name[i] > 160 && name[i] < 255) chname += name[i..i];

        if( chname != sgjob["sgjob"] )
                return notify_fail("��ͷ��˵�����ⲻ������Ҫ�ġ�\n");

        bonus = sgjob["exp_bonus"];
        bonus = bonus + random(bonus);
        who->add("combat_exp", bonus);
        who->add("shen", -bonus);

        bonus = sgjob["score"];
        bonus = bonus + random(bonus);
        who->add("sg/exp", bonus);

        who->delete("sgjob");
        who->set("sg_ok/stuff", 1);

        remove_call_out("store");
        call_out("store", 1, ob);

        log_file("test/Sgstff", sprintf("%s��%sʱ�Ͻ���%s\n", who->query("name"), ctime(time()), chname));
        command("nod " + who->query("id"));
        return 1;
}

void gototalk(object me)
{
        object ob = this_object();
        string str;

        str = meetplaces[random(sizeof(meetplaces))];

        command("whisper " + me->query("id") + " " + "���˵�������㣬����ȥ����" + (load_object(str))->query("short") + "̸�ɡ�");

        set_pang(me, "a");

        message("vision", 
                "����ææ���뿪�ˡ�\n", 
                environment(ob), ({ob}));

        ob->move(str);
        message("vision", 
                "��ͷ�����˹�����\n",
                environment(ob), ({ob}));

        remove_call_out("do_back");
        call_out("do_back", 30 + random(30), ob);
}

void do_back(object ob)
{
        if( !ob )  return;

        if( ob->is_busy() || ob->is_fighting() || !living(ob) )
                call_out("do_back", 10 + random(10));
        else {
                message("vision", 
                        "��ͷ��һת�۱���ʧ�ˡ�\n", 
                        environment(ob), ({ob}));
//              ob->move(PANGHOME);
                ob->move(homes[random(sizeof(homes))]);
                message("vision", 
                        "��ͷ�Ӵ����˹�����\n", 
                        environment(ob), ({ob}));

                del_busyfor();
        }
}

void set_pang(object ob, string type)
{
        string *types = ({"a", "b", "c"});

        if( member_array(type, types) == -1 )
                return;

        types -= ({type});

        ob->set_temp("pang/" + type, 1);
        for(int i = 0; i < sizeof(types); i++)
                ob->delete_temp("pang/" + types[i]);

        remove_call_out("del_busyfor");
        call_out("del_busyfor", 20 + random(20));
}

void del_busyfor()
{
        object ob;
        string p_id;

        if( !stringp(p_id = (string)query_temp("busyfor")) ) return;

        if( ob = find_player(p_id) ) 
                 ob->delete_temp("pang");

        delete_temp("busyfor");
}

void store(object ob)
{
        if( !ob ) return;

        if( !ob->is_unique() )  destruct(ob);
        else ob->move(SGCANGKU);
}

private int is_other(object ob, object me)
{
        if( userp(ob) && ob != me && living(ob) )  return 1;
        return 0;
}

private int is_suitable(object victim, object killer)
{
        object room;
        mapping map;

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

private int is_candidate(object victim, object forcer)
{
        string *no_force_list = ({
                "mu ren",
                "mengzhu",
                "shangshan shizhe",
                "fae shizhe",
                "xuantong dashi",
                "huang zhen",
                "juexin dashi",
                "ren woxing",
                "zhuoma",
        });

        if( victim->query("combat_exp") < forcer->query("combat_exp")
         || victim->query("combat_exp") > forcer->query("combat_exp") * 2
         || !clonep(victim) || userp(victim)
         || victim->query("race") != "����"
         || victim->query("winner")
         || victim->query("family/family_name") == "������"
         || victim->query("sg/spy") 
         || strsrch(base_name(victim), "/d/xiakedao/") == 0
         || strsrch(base_name(victim), "/d/death/") == 0
         || strsrch(base_name(victim), "/d/shenlong/") == 0
         || strsrch(base_name(victim), "/u/") == 0
         || base_name(victim) == "/kungfu/skill/yanxing-dao/copy/user"
         || member_array(victim->query("id"), no_force_list) != -1 )
                 return 0;

        return 1;
}

void apply_yj(object me)
{
        me = this_player();

        if ( me->query("yijin_wan") >= me->query("age") - 13 ) {
                me->add("max_neili",  -5);
                me->add("max_jingli", -5);
                apply_gift(me, -1);
                message("vision", me->name() + "һ�ڰ���ҩ������ȥ�����ž͵��ڵ��ϣ����²�֪�ˡ�\n" NOR, environment(me), me);
                tell_object(me, HIR "������һ����̥�׽��裬ֻ���ø�ʹ��ʣ�����������ת��ԭ����ʳ̫�࣬������綾��\n" NOR);
                me->unconcious();
        } else {
                me->add("max_neili",  5);
                me->add("max_jingli", 5);
                me->set("yijin_wan", me->query("age") - 13);
                apply_gift(me, 1);
                message("vision", me->name() + "һ�����±�̥�׽��裬ֻ������ɫ�ɰ�ת�̣�����ת�ڣ����ɺ�ת�죬һֱ���˺ü��Σ��Ž����ָ�ԭ����\n" NOR, environment(me), me);
                tell_object(me, HIG "��һ���±�̥�׽��裬�����Ϣ���ȣ����˰�ӿ����֫�ٺ���ȫ��ǽڸ���졣" 
                                + "\n�����־��������࣬�����ڿշ�ȥ���������Ѿ���̥���ǣ���������ˣ�\n" NOR, me);

        }

        tell_object(me, "��ȷ����裬����һ����ٴη��ã����������𣡣���\n");

}

void apply_gift(object me, int flag)
{
        int i;
        int tmpstr, tmpint, tmpcon, tmpdex, tot;
        mapping my = me->query_entire_dbase();

        if( flag == -1 ) {
        tmpstr = tmpint = tmpcon = tmpdex = 10 + flag;

        for (i = 0; i < 40; i++) {
                switch (random(4)) {
                        case 0: tmpstr++; break;
                        case 1: tmpint++; break;
                        case 2: tmpcon++; break;
                        case 3: tmpdex++; break;
                }
        }

        if (tmpstr <= 30) my["str"] = tmpstr;   else my["str"] = 30;
        if (tmpint <= 30) my["int"] = tmpint;   else my["int"] = 30;
        if (tmpcon <= 30) my["con"] = tmpcon;   else my["con"] = 30;
        if (tmpdex <= 30) my["dex"] = tmpdex;   else my["dex"] = 30;
        return;
        }

        tot = 84 - my["str"] - my["int"] - my["con"] - my["dex"];
        for(i = 0; i < tot; i++) {
                switch (random(4)) {
                        case 0: my["str"]++; break;
                        case 1: my["int"]++; break;
                        case 2: my["con"]++; break;
                        case 3: my["dex"]++; break;
                }
        }
}

string assign_job(object me)
{
        object ob, victim, cangku;
        mapping sgjob, map;
        string *times;
        mixed victim_list, stuff_list;
        int i, myexp;

        string *levels = ({
               "20000",
               "50000",
              "100000",
              "500000",
             "1000000",
             "2000000"
        });

        myexp = (int)me->query("combat_exp");
        myexp = (4 * myexp + random(2 * myexp)) / 5;
        if( myexp < 10000 ) return "";

        for( i = 0; i < sizeof(levels); i++ ) 
               if( myexp < atoi(levels[i]) ) break;

        sgjob = (SGJOBS + levels[i])->query_sgjob();
        if( !sgjob ) return "";

        if( !present("mianzhao", me) ) {
                ob = new(SGZHAO);
                ob->set("owner", me);
                ob->move(me);
                message_vision("$N����$nһ" + ob->query("unit") + ob->name() + "��\n", this_object(), me);
        }

        switch(sgjob["sgjob"]) {
        case "FORCEJOIN":
                if( !(victim_list = filter_array(livings(), "is_candidate", this_object(), me)) )
                        return "";
                victim = victim_list[random(sizeof(victim_list))];
                me->set("sgjob/forcejoin", victim->query("id"));
                me->set("sgjob/assigntime", time());
                log_file("test/ShenlongJob", sprintf("%s��%sʱ��ָ��ȥ��%s��������\n", me->query("name"), ctime(time()), victim->name()));
                return "��ȥ��" + victim->query("name") + "������������";
                break;

        case "PK":
                if( mapp(map = me->query("sg_victim")) ) {
                        times = keys(map);
                        for(i = 0; i < sizeof(times); i++) {
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

                log_file("test/ShenlongJob", sprintf("%s��%sʱ��ָ��ȥ׷ɱ%s\n", me->query("name"), ctime(time()), (string)me->query("sgjob/victim_name")));
                return "��ȥ��" + (string)me->query("sgjob/victim_name") + "(" + (string)me->query("sgjob/victim_id") + ")" + "ɱ��";
                break;

        default: break;
        }

        if( sgjob["sgjob_type"] == "Ѱ" ) {
                if( !(cangku = find_object(SGCANGKU)) )
                        cangku = load_object(SGCANGKU);

                if( stuff_list = cangku->query("stuff_list") ) 
                        if( member_array(sgjob["sgjob"], stuff_list) != -1 )
                                return "";

                if( sgjob["sgjob"] == "�����ؼ�" )
                sgjob["sgjob"] = shaolinbooks[random(sizeof(shaolinbooks))];
                me->set("sgjob", sgjob);
                me->set("sgjob/assigntime", time());
                log_file("test/ShenlongJob", sprintf("%s��%sʱ��ָ��ȥ��%s\n", me->query("name"), ctime(time()), sgjob["sgjob"] ));
                return "��ȥ��" + sgjob["sgjob"] + "����";
        }

        return "";
}








