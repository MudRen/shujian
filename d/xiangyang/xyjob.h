// ����ˢ����ĵص�,������������й����и����־   By lsxk@hsbbs
// ����.h �ļ�ɾ��job ������ǰ��kill �Ǻŷ�ֹ����job ����������μ�HD job����add tj By server
// job�����󡣽��Զ�ȡ��id��ͨ��״̬(����chousui-zhang/qianzhu-wandushou) By Spiderii@ty
//Update by lsxk@hsbbs 2008/1/10   ����ͳһ����TASKREWARD_D�����㡣

#define JOB_REFRESH_PLACE "/d/xiangyang/cross2"

// ���񷿼�
string* xyjob_room = ({
        __DIR__"baihumen",
        __DIR__"bank",
        __DIR__"baozipu",
        __DIR__"bcx1",
        __DIR__"bcx2",
        __DIR__"bcx3",
        __DIR__"bcx4",
        __DIR__"bhmnj",
        __DIR__"bingying",
        __DIR__"bjie1",
        __DIR__"bjie2",
        __DIR__"bjie3",
        __DIR__"chalou",
        __DIR__"chalou2",
        __DIR__"chayedian",
        __DIR__"chemahang",
        __DIR__"eroad1",
        __DIR__"chengyipu",
        __DIR__"chucshi",
        __DIR__"cross1",
        __DIR__"cross2",
        __DIR__"chengyipu",
        __DIR__"damen",
        __DIR__"datiepu",
        __DIR__"dcx1",
        __DIR__"dcx2",
        __DIR__"dcx3",
        __DIR__"dcx4",
        __DIR__"dcx5",
        __DIR__"djie1",
        __DIR__"djie2",
        __DIR__"doufufang",


        __DIR__"dpailou",
        __DIR__"eroad1",
        __DIR__"feizhai",
        __DIR__"guangc",
        __DIR__"junying",
        __DIR__"mujiangpu",
        __DIR__"ncx1",
        __DIR__"ncx2",
        __DIR__"ncx4",
        __DIR__"ncx3",
        __DIR__"ncx5",
        __DIR__"njie1",
        __DIR__"njie2",
        __DIR__"njie3",
        __DIR__"nroad1",
        __DIR__"outeroad1",
        __DIR__"outnroad1",
        __DIR__"outsroad1",
        __DIR__"outwroad1",
        __DIR__"qinglongmen",
        __DIR__"shaobingpu",
        __DIR__"shuoshug",
        __DIR__"sishu",
        __DIR__"xcx1",
        __DIR__"xiaocd",
        __DIR__"xcx2",
        __DIR__"xcx3",
        __DIR__"xcx4",
        __DIR__"xcx5",
        __DIR__"xiyuan",
        __DIR__"xjie",
        __DIR__"xpailou",



        __DIR__"xuanwumen",
        __DIR__"xyudian",
        __DIR__"yamen",
        __DIR__"yaopu",
        __DIR__"yingzhang",
        __DIR__"ymzhengting",
        __DIR__"zahuopu",
        __DIR__"zhuquemen",
        __DIR__"zqmnj",
        __DIR__"zrdian",
});

void xyjob_1() //����׼��
{
        object guo = present("guo jing", load_object("/d/xiangyang/xuanwumen"));
        object meng = present("meng ge", load_object("/d/xiangyang/yingzhang"));

        if(JOB_REFRESH_PLACE->query("xyjobing")) return;

        if (!meng || !guo)
        {
        	remove_call_out("xyjob_1");
        	call_out("reset_xyjob",300 + random(180));
        	return;
        }
        CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"��˵�ɹű�Ӫ�����ټ�����׼������������");
        CHANNEL_D->do_channel(meng, "chat", "��ԭ�������ǣ������˻ʵۻ�ӹ�����ɹŷ��ܴ������°��ݣ�");
        CHANNEL_D->do_channel(meng, "chat", "��������ϣ��ս�����꣬����������ָ��֣������������ξ���Ȼ�������ң�");
        CHANNEL_D->do_channel(guo, "chat", "���˵������ɺ����Լ����������������˻�������ԭ��");
        CHANNEL_D->do_channel(guo, "chat", "��λӢ����Ů����ԭ�����˾������������ˣ���һչ���֣�Ϊ���ҳ����ɣ�");
        guo->set("ready_defend", 1);
        meng->set("ready_attack", 1);
        JOB_REFRESH_PLACE->set("xyjobing",1);
        remove_call_out("xyjob_1");
        call_out("xyjob_2", 200);
}

void xyjob_2() // ����ʼ
{
        int at, df, a_exp, d_exp, i = 0;
        object weishi;
        object guo = present("guo jing", load_object("/d/xiangyang/xuanwumen"));
        object meng = present("meng ge", load_object("/d/xiangyang/yingzhang"));
        object *attackers = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/mg_attack") :));
        object *defenders = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/xy_defend") :));
        string room;

        df = sizeof(defenders);
        at = sizeof(attackers);

        if (!guo)
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"������˧�����ѱ�ɱ���ɹž�ת�ƹ����ˣ�");
                remove_call_out("xyjob_2");
                call_out("reset_xyjob", 5);
        }
        else if (!meng)
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"�ɹž���˧�ɸ��ѱ�ɱ��������ɢ�ˣ�");
                remove_call_out("xyjob_2");
                call_out("reset_xyjob", 5);
        }
        else if (df < 3)
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"�����ؾ����㣬�ɹž�ֻ����������ʿ����Ӿ������ˣ�");
                remove_call_out("xyjob_2");
                call_out("reset_xyjob", 5);
        }
        else if (at < 3)
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"�ɹž���֯��������ֲ��㣬��ʱ�����������Ľ�����");
                remove_call_out("xyjob_2");
                call_out("reset_xyjob", 5);
        }
        else
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"�ɹž���ʼ�������Ľ�����");
                CHANNEL_D->do_channel(meng, "chat", "Ŀ��������ɱ����������Щ���ָ��֣��������������ҵ��ˣ�");
                CHANNEL_D->do_channel(guo, "chat", "Ц����¹��˭�ֻ���֪���أ������ʶ��ʶ������ԭ�ĸ��֣�");
                guo->set("start_defend",1);
                meng->set("start_attack",1);
                while(i < 3)
                {
                        weishi = new("/d/xiangyang/npc/weishi");
                        weishi->move("/d/xiangyang/xuanwumen");
                        weishi = new("/d/xiangyang/npc/weishi");
                        weishi->move("/d/xiangyang/zhuquemen");
                        weishi = new("/d/xiangyang/npc/weishi");
                        weishi->move("/d/xiangyang/qinglongmen");
                        weishi = new("/d/xiangyang/npc/weishi");
                        weishi->move("/d/xiangyang/baihumen");
                        weishi = new("/d/xiangyang/npc/weishi");
                        weishi->move("/d/xiangyang/cross2");
                        i ++ ;
                }
                reset_eval_cost();
                for(i = 0; i < at; i++)
                {
                        room = xyjob_room[random(sizeof(xyjob_room))];
                        attackers[i]->set_temp("xyjob/attack_ready",1);
                        if (attackers[i]->is_ghost() || !attackers[i]->query_temp("special_die"))
                        	continue;
                        attackers[i]->move(room);
                }
                for(i = 0; i < df; i++)
                {
                        room = xyjob_room[random(sizeof(xyjob_room))];
                        defenders[i]->set_temp("xyjob/defend_ready",1);
                        if (defenders[i]->is_ghost() || !defenders[i]->query_temp("special_die"))
                        	continue;
                        defenders[i]->move(room);
                }
                call_out("xyjob_random_move", 10);
                remove_call_out("xyjob_2");
            	call_out("xyjob_3", 300);
            	for(i = 0; i < df; i++)
                    	d_exp += defenders[i]->query("combat_exp");
                for(i = 0; i < at; i++)
                    	a_exp += attackers[i]->query("combat_exp");
                log_file("job/xyjob", sprintf("%s ��������ս��ʼ������%d�˾��鹲%d���ط�%d�˾��鹲%d��\n",
                ctime(time())[4..19],sizeof(attackers),a_exp,sizeof(defenders),d_exp));
        }
}

void xyjob_3() // �ж�ʤ��
{
        int i, at, df;
        object guo = present("guo jing", load_object("/d/xiangyang/xuanwumen"));
        object meng = present("meng ge", load_object("/d/xiangyang/yingzhang"));
        object *attackers = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/mg_attack") :));
        object *defenders = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/xy_defend") :));
        object *attacker = filter_array(attackers, (: $1->query_temp("living") :));
        object *defender = filter_array(defenders, (: $1->query_temp("living") :));

	df = sizeof(defenders);
        at = sizeof(attackers);

        if (sizeof(attacker) > sizeof(defender))
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"��˵�ɹű������������ǣ�");
                for(i = 0; i < at; i++)
                        attackers[i]->add_temp("xyjob/attack", 1);
        }
        else
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"��˵�����ؾ�ɱ�����ɹž���");
                for(i = 0; i < df; i++)
                        defenders[i]->add_temp("xyjob/defend", 1);
        }

        if (!guo)
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"�����ؾ���˧����ѳ�ѣ�");
        else
        {
                guo->delete("ready_defend");
                guo->delete("start_defend");
        }

        if (!meng)
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"�ɹž���˧�ɸ�ѳ�ѣ�");
        else
        {
                meng->delete("ready_attack");
                meng->delete("start_attack");
        }
        remove_call_out("xyjob_random_move");
        remove_call_out("xyjob_3");
	call_out("xyjob_4", 5);
}

void xyjob_4() // ���Ž���
{
        int i, at, df, exp, nexp, pot, SJ_Credit;
        object *attackers = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/mg_attack") :));
        object *defenders = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/xy_defend") :));

	at = sizeof(attackers);
	df = sizeof(defenders);

        for(i = 0; i < at; i++)
        {

/*
                exp = attackers[i]->query_temp("xyjob/attack")*800;
                if (exp <= 0)
                        exp = 400;
                exp += random(exp/4);
                if (exp > 1000 + 200*df)
                        exp = 1000 + 200*df -random(200);
                if (exp > 3500)
                	exp = 3400 + random(101);
                nexp = exp;
                pot = exp/6 +random(exp/10);
                SJ_Credit = exp*2/400;
                attackers[i]->add("SJ_Credit",SJ_Credit);
                attackers[i]->add("combat_exp",exp);
                if(attackers[i]->query("potential") + pot > attackers[i]->query("max_pot"))
                        attackers[i]->set("potential", attackers[i]->query("max_pot"));
                else
                        attackers[i]->add("potential", pot);
                message_vision(HIW"\n$N�����"+CHINESE_D->chinese_number(exp)+
                "�㾭�飬"+ CHINESE_D->chinese_number(pot)+
                "��Ǳ�ܵĽ�����\n"+HIR+"\n$N���⻹�����"+ CHINESE_D->chinese_number(SJ_Credit)+"������ͨ��\n"NOR, attackers[i]);
                attackers[i]->add("shen",-nexp);
                message_vision(HIW"\n$N����һ��а������������\n"NOR,attackers[i]);
                attackers[i]->add("job_time/��������",1);
*/

                SJ_Credit = (attackers[i]->query_temp("xyjob/attack") - 1) * 2;
                if(SJ_Credit<0) SJ_Credit = 0;

                TASKREWARD_D->get_reward(attackers[i],"��������",-1,0,SJ_Credit+2,0,4,attackers[i]->query_temp("xyjob/attack")-1,15000+random(5000));

                attackers[i]->clear_conditions_by_type("poison");
                attackers[i]->clear_conditions_by_type("hurt");
                attackers[i]->clear_conditions_by_type("busy");
                attackers[i]->clear_conditions_by_type("zhenqi");
                attackers[i]->clear_condition("killer"); // By Spiderii@ty
                attackers[i]->remove_all_killer();
                attackers[i]->delete_temp("kill_other");
                attackers[i]->delete_temp("other_kill");
                attackers[i]->dismiss_team();
                attackers[i]->clear_condition("job_busy");
/*
                log_file("job/xyjob", sprintf("%s %s(%s)%d�ι��ǵõ�����%d��Ǳ��%d��ͨ��%d��\n",
                ctime(time())[4..19],attackers[i]->name(1),attackers[i]->query("id"),(int)attackers[i]->query("job_time/��������"),exp,pot,SJ_Credit));
*/
        }
        for(i = 0; i < df; i++)
        {
/*
                exp = defenders[i]->query_temp("xyjob/defend")*800;
                if (exp <= 0)
                        exp = 400;
                exp += random(exp/4);
                if (exp > 1000 + 200*at)
                        exp = 1000 + 200*at -random(200);
                if (exp > 3500)
                	exp = 3400 + random(101);
                nexp = exp;
                SJ_Credit = exp*2/400;
                pot = exp/6 +random(exp/10);
                defenders[i]->add("SJ_Credit",SJ_Credit);
                defenders[i]->add("combat_exp",exp);
                if (defenders[i]->query("potential") + pot > defenders[i]->query("max_pot"))
                        defenders[i]->set("potential", defenders[i]->query("max_pot"));
                else
                        defenders[i]->add("potential", pot);
                message_vision(HIW"\n$N�����"+CHINESE_D->chinese_number(exp)+
                "�㾭�飬"+ CHINESE_D->chinese_number(pot)+
                "��Ǳ�ܵĽ�����\n"+HIR+"\n$N���⻹�����"+ CHINESE_D->chinese_number(SJ_Credit)+"������ͨ��\n"NOR, defenders[i]);
                defenders[i]->add("shen",nexp);
                message_vision(HIW"\n$N���������������ˣ�\n"NOR,defenders[i]);
                defenders[i]->add("job_time/��������",1);
*/

                SJ_Credit = (defenders[i]->query_temp("xyjob/defend") - 1) * 2;
                if(SJ_Credit<0) SJ_Credit = 0;
                TASKREWARD_D->get_reward(defenders[i],"��������",1,0,SJ_Credit+2,0,4,defenders[i]->query_temp("xyjob/defend")-1,15000+random(5000));

                defenders[i]->clear_conditions_by_type("poison");
                defenders[i]->clear_conditions_by_type("hurt");
                defenders[i]->clear_conditions_by_type("busy");
                defenders[i]->clear_conditions_by_type("zhenqi");
                defenders[i]->clear_condition("killer"); // By Spiderii@ty
                defenders[i]->remove_all_killer();
                defenders[i]->delete_temp("kill_other");
                defenders[i]->delete_temp("other_kill");
                defenders[i]->dismiss_team();
                defenders[i]->clear_condition("job_busy");
/*
                log_file("job/xyjob", sprintf("%s %s(%s)%d���سǵõ�����%d��Ǳ��%d������ͨ��%d��\n",
                ctime(time())[4..19],defenders[i]->name(1),defenders[i]->query("id"),(int)defenders[i]->query("job_time/��������"),exp,pot,SJ_Credit));
*/
        }
        remove_call_out("xyjob_4");
        call_out("reset_xyjob", 5);
        "/cmds/std/xyjob"->xyjob_reset();
}

void reset_xyjob() // reset all
{
        int i, at, df;
        object *inv, room;
        object guo = present("guo jing", load_object("/d/xiangyang/xuanwumen"));
        object meng = present("meng ge", load_object("/d/xiangyang/yingzhang"));
        object *attackers = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/mg_attack") :));
        object *defenders = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/xy_defend") :));

	at = sizeof(attackers);
	df = sizeof(defenders);

        for(i = 0; i < at; i++)
        	attackers[i]->clear_condition("job_busy");
        for(i = 0; i < df; i++)
		defenders[i]->clear_condition("job_busy");

        "/cmds/std/xyjob"->xyjob_reset();
        JOB_REFRESH_PLACE->delete("xyjobing");

        if (guo)
        {
                guo->delete("ready_defend");
                guo->delete("start_defend");
        }
        else
        {
                guo = new("/kungfu/class/gaibang/guojing");
                guo->move("/d/xiangyang/xuanwumen");
        }

        if (meng)
        {
                meng->delete("ready_attack");
                meng->delete("start_attack");
        }
        else
        {
                meng = new("/d/xiangyang/npc/mengge");
                meng->move("/d/xiangyang/yingzhang");
        }

        room = load_object("/d/xiangyang/xuanwumen");
        inv = all_inventory(room);
        i = sizeof(inv);
        while (i--)
                if (inv[i]->query("id") == "weishi")
                        destruct(inv[i]);
        room = load_object("/d/xiangyang/zhuquemen");
        inv = all_inventory(room);
        i = sizeof(inv);
        while (i--)
                if (inv[i]->query("id") == "weishi")
                        destruct(inv[i]);
        room = load_object("/d/xiangyang/baihumen");
        inv = all_inventory(room);
        i = sizeof(inv);
        while (i--)
                if (inv[i]->query("id") == "weishi")
                        destruct(inv[i]);
        room = load_object("/d/xiangyang/qinglongmen");
        inv = all_inventory(room);
        i = sizeof(inv);
        while (i--)
                if (inv[i]->query("id") == "weishi")
                        destruct(inv[i]);
        room = load_object("/d/xiangyang/cross2");
        inv = all_inventory(room);
        i = sizeof(inv);
        while (i--)
                if (inv[i]->query("id") == "weishi")
                        destruct(inv[i]);
        reset_job();
}

int xyjob_attack_check(object ob)
{
        if (userp(ob) && ob->query_temp("xyjob/mg_attack") && ob->query_temp("living"))
		return 1;
	return 0;
}

int xyjob_defend_check(object ob)
{
        if (userp(ob) && ob->query_temp("xyjob/xy_defend") && ob->query_temp("living"))
		return 1;
	return 0;
}

void xyjob_random_move() // �������
{
        int i, j, at ,df;
        object *attackers = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/mg_attack") :));
        object *defenders = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/xy_defend") :));
        object *attacker = filter_array(attackers, (: $1->query_temp("living") :));
        object *defender = filter_array(defenders, (: $1->query_temp("living") :));
        object *obj, *at_rooms = ({}), *df_rooms = ({});

	at = sizeof(attacker);
	df = sizeof(defender);

        for (i = 0; i < at; i ++)
        {
                foreach (object room in at_rooms)
                	if (room == environment(attacker[i]))
                		continue;
        	at_rooms += ({environment(attacker[i])});
        }
        for (i = 0; i < df; i ++)
        {
        	foreach (object room in df_rooms)
                	if (room == environment(defender[i]))
                		continue;
                df_rooms += ({environment(defender[i])});
        }

	at = sizeof(at_rooms);
	df = sizeof(df_rooms);

	for (i = 0; i < at; i ++)
	{
		obj = all_inventory(at_rooms[i]);
		obj = filter_array(obj, (: xyjob_attack_check :));
		if (sizeof(obj) > 3)
			for (j = 0;j < sizeof(obj);j ++)
			{
				if (obj[j]->is_fighting())
					continue;
				obj[j]->move(xyjob_room[random(sizeof(xyjob_room))]);
				tell_object(obj[j], "����������ǰ�������ڴ˵��飬��ȥ���³ǳأ�\n");
			}
        }
	for (i = 0; i < df; i ++)
	{
		obj = all_inventory(df_rooms[i]);
		obj = filter_array(obj, (: xyjob_defend_check :));
		if (sizeof(obj) > 3)
			for (j = 0;j < sizeof(obj);j ++)
			{
				if (obj[j]->is_fighting())
					continue;
				obj[j]->move(xyjob_room[random(sizeof(xyjob_room))]);
				tell_object(obj[j], "�������ڹ��ǣ������ڴ˵��飬��ȥ������ˣ�\n");
			}
        }
       	remove_call_out("xyjob_random_move");
	call_out("xyjob_random_move", 10);
}
