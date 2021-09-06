// by fengyue

inherit NPC;
#include <ansi.h>


string* luns = ({
       BINGQI_D("gold-falun"),
       BINGQI_D("silver-falun"),
       BINGQI_D("bronze-falun"),
       BINGQI_D("iron-falun"),
       BINGQI_D("leaden-falun"),
});


void create()
{
        object weapon;
        set_name("金轮法王", ({ "jinlun fawang", "jinlunfawang","fawang" ,"jinlun"}));
        set("long",@LONG
他身材高瘦，脸颊深陷，双目看似无神，两边太阳穴却高高凸起，面容严肃。
他受封“蒙古国第一国师”，练得一身通天彻地的神功。
LONG
        );
        set("title", HIY "蒙古国第一国师" NOR);
        set("gender", "男性");
        set("class", "huanxi");
        set("age", 65);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("dex", 34);
        set("per", 22);

        set("max_qi", 9500);
        set("max_jing", 6500);
        set("eff_jingli", 7500);
        set("neili", 18000);
        set("max_neili", 18000);
        set("jiali", 100);
        set("combat_exp", 4500000);
        set("score", 28000);
        set("unique", 1);

        set_skill("huanxi-chan", 200);
        set_skill("literate", 200);
        set_skill("force", 360);
        set_skill("longxiang-boruo", 360);
        set_skill("dodge", 380);
        set_skill("yuxue-dunxing", 380);
        set_skill("hammer", 380);
        set_skill("xiangfu-lun", 380);
        set_skill("hand", 340);
        set_skill("dashou-yin",340);
        set_skill("claw", 340);
        set_skill("tianwang-zhua", 340);
        set_skill("parry", 360 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hammer", "xiangfu-lun");
        map_skill("parry", "xiangfu-lun");
        map_skill("hand","dashou-yin");
        map_skill("claw","tianwang-zhua");

        prepare_skill("hand","dashou-yin");
        prepare_skill("claw","tianwang-zhua");

        create_family("大轮寺", 10, "弟子");
       
        set("lun_count",5);
        set("lun_count2",1);
        set("class", "huanxi");
        set("chat_chance", 2);     
        set("chat_msg", ({
		CYN"金轮法王傲然道：第十层龙象般若功我已融会贯通，古往今来，我是第二人！\n"NOR,
		CYN"金轮法王愤愤的道：中原武人不讲规矩，仗着人多，大伙儿来个一拥而上。\n"NOR,
		CYN"金轮法王愤愤的道: 哼，否则凭我一人之力当可取得武林盟主之位。\n"NOR,
	}) );
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "shield jinlun fawang" :),
                (: perform_action, "hammer.wushuai" :), 
	}));

        set_temp("apply/damage", 70);
        set_temp("apply/dodge", 80);
        set_temp("apply/attack", 60);
        set_temp("apply/armor", 60);

        setup();
	if (clonep()){
                weapon = unew(BINGQI_D("gold-falun"));
                if (!weapon) weapon = unew(BINGQI_D("silver-falun"));
                if (!weapon) weapon = unew(BINGQI_D("bronze-falun"));
                if (!weapon) weapon = unew(BINGQI_D("iron-falun"));
                if (!weapon) weapon = unew(BINGQI_D("leaden-falun"));
                weapon->move(this_object());
                weapon->wield();
                carry_object("/d/xueshan/npc/obj/longxiang-jiasha")->wear();       
                add_money("gold",2);
        }
}


 void init()
 {
	object me = this_player();
       	::init();
	if ( me->query_temp("/quest/tzauto/yideng") == 1) {
                command("chat 何人竟敢夜闯中军大帐，只怕你有命来无命回了！ ");
                command("chat* sneer "+me->query("id"));
start_busy(2);
                                kill_ob(me);
		me->fight_ob(this_object());
                me->delete_temp("quest/tzauto/yideng");
                me->set_temp("quest/tzauto/dajiu",1);  
	}
}
 
 void die()

 {
       message_vision("$N恨恨的对你说：“这次算你命大！”。\n", this_object());
       message_vision("$N几个起落就不见了。\n", this_object());
       destruct(this_object());
    
}






