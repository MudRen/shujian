//Cracked by Roath
// mizheng.c ��������
// ��������٣��ʹ��������ͷ�����¼����Ǩ��������	-chu

#include <ansi.h>
#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif

#include "/d/beijing/beijing_defs.h"

inherit NPC;
inherit F_SAVE;

string do_toujun();
string do_tuiyi();
string do_shengqian();
string do_members();
string do_news();

void create()
{
    int i, *speed_cur;

    seteuid(getuid());
    set_name("����", ({"mi zheng", "mi"}));
    set("title", "��������");
    set("gender", "����");
    set("age", 30);
    set("long", "�����ǵ���͢�ı������飬\n"
    "������������ٵ���Ǩ��ȫ�����ˡ�\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    setup();
    carry_object("/d/city/obj/cloth")->wear();
    if (! restore() ) {
	speed_cur = allocate(7);

	for (i=0; i<7; i++) {
	    speed_cur[i] = HELPER->speed_base(i);
	}
	set("speed_cur", speed_cur);
	save();		// for the first time
    }
    remove_call_out("refresh_members");
    call_out("refresh_members", 1200);  // do it every 20 min
}

int init()
{
	set("inquiry", ([
	"���" : "�����ȥ�ʾ�Ӫ�Ķ��ܹܰɡ�",
	"suicong" : "�����ȥ�ʾ�Ӫ�Ķ��ܹܰɡ�",
	"����" : "�����ȥ�ʾ�Ӫ�Ķ��ܹܰɡ�",
	"job" : "�����ȥ�ʾ�Ӫ�Ķ��ܹܰɡ�",
	"here" : "����������ñ������š�",
	"����" : "����ͳ������Ӫ�����ջ��Ͽ��������¹ٴ�������Ӫ��",
	"Ͷ��" : (: do_toujun :),
	"join" : (: do_toujun :),
	"��Ǩ" : (: do_shengqian :),
	"����" : (: do_shengqian :),
	"promote" : (: do_shengqian :),
	"����" : (: do_tuiyi :),
	"����" : (: do_tuiyi :),
	"retire"  : (: do_tuiyi :),
	"����"      : (: do_news :),
	"ͨ��"      : (: do_news :),
	"news"      : (: do_news :),
	"����"   : (: do_members :),
	"����"   : (: do_members :),
	"members"   : (: do_members :),
	]));
}

string query_save_file()
{
    return NPCDATA+"mizheng";
}

/****************** UTILITY METHODS **************************/

void post_message(string msg)
{
    object me = this_object();
    string *news = me->query("bingbu/news");
    int     news_num = me->query("bingbu/news_num");
    int     i, diff;
#define MAX_NEWS 50

    if (news) { // purge old news
	if (news_num >= MAX_NEWS) {
	    diff = news_num - MAX_NEWS + 1;
	    for (i=0; i<news_num-diff; i++){
		news[i] = news[i+diff];
	    }
	}
    }else {
	news = allocate(MAX_NEWS);
	news_num = 0;
    }
    news[news_num++] = msg;
    me->set("bingbu/news", news);
    me->set("bingbu/news_num", news_num);
    save();
}

int *pos_ratio()
{
    object me = this_object();
    int *ret;
    int i, j;
    string *members;

    ret = ({0, 0, 0, 0, 0, 0, 0});
    for (i=0; i<7; i++){
	members = me->query("members/rank"+i);
        for (j=0; j<sizeof(members); j++){
	    if (members[j] != 0) {
	        ret[i] ++;
 	    }
	}
	if (ret[i] > 0)
	    ret[i] = 100*ret[i]/sizeof(members);
    }
    
    return ret;
}

int player_rank(string id)
{
    object me = this_object();
    int i, j;
    string *members;

    for (i=0; i<7; i++){
	members = me->query("members/rank"+i);
        for (j=0; j<sizeof(members); j++){
	    if (members[j] == id) {
	        return i;
 	    }
	}
    }
    return -1;
}

object get_player(string id)
{
    object usr;
    
    usr = find_player(id);
    if (! usr) {
	usr->set_temp("temp_dummy", 1);
	usr = new("/clone/test/dummy");
	usr->set("id", id);
	if ( !usr->restore() ) {
	    return 0;
	}
    }
    return usr;
}

int add_user_succ(object me, object player, int rank)
{
    int slot, i;
    string *members;

    members = me->query("members/rank"+rank);
    if (!members) {
	members = allocate(HELPER->rank_position_num(rank));
  	for (i=0; i<sizeof(members); i++){
	    members[i] = 0;
	}
	slot = 0;
    }else{
  	for (i=0; i<sizeof(members); i++){
	    if (members[i] == 0) slot = i;
	    break;
	}
        if (i == sizeof(members))
	    return 0;
    }

    player->set("family/generation", rank);
    player->set("bingbu/death_count", player->query("death_count"));
    player->set("bingbu/job_cur", 0);
    player->set("bingbu/job_lazy", 0);
    player->set("bingbu/job_lazy_time", time());
    player->set("bingbu/job_lazy_mud", 0);
    player->set("bingbu/job_lazy_mudtime", player->query("mud_age"));
    player->set("bingbu/last_check", player->query("mud_age"));

    if (rank >= 5) {
	player->set("bingbu/dept", HELPER->dept_name(slot%2));
	player->set("title", player->query("bingbu/dept")+HELPER->rank_name(rank));
    }else{
	player->set("title", HELPER->rank_name(rank));
    }
    player->save();

    members[slot] = player->query("id");
    me->set("members/rank"+rank, members);
    me->save();
    return 1;
}

void normalize(object player)
{
    object *obs, ob;

    obs=filter_array(children("/d/beijing/obj/yaopai.c"), (: clonep :));
    if (sizeof(obs) > 0){
	foreach (ob in obs) {
	    if (environment(ob) == player) {
		destruct(ob);
		if (environment(player) == environment(this_object()))
		    message_vision("$N��$n�����Ͻ���һ���������ơ�\n", 
			this_object(), player);
	    }
	}
    }
    player->delete("family");
    player->set("title","��ͨ����");
    player->save();
}

/****************** CALL_BACK METHODS **************************/

string do_news()
{
    object me = this_object();
    object player = this_player();
    string *news = me->query("bingbu/news");
    int     news_num = me->query("bingbu/news_num");
    int     i;

    if (! IS_SHIWEI(player)) {
	return "�㲻�����־���������θ���������!";
    }
    message_vision("$N��$n����һ�۱�����ͨ�ġ�\n", me, player);
    tell_object(player, "----------------����ͨ��-------------\n");
    for (i=0; i<news_num; i++){
	tell_object(player, news[i]);
    }
    return "����͸Ͻ��߰ɡ�";
}

string do_members()
{
    object me = this_object();
    object player = this_player();
    object usr;
    int    rank, i, num;
    string *members, *ret, *name;
    
    if (! IS_SHIWEI(player)) {
	return "�㲻�����־���������θ���������!";
    }

    if (time() - player->query("bingbu/ask_member") < 3600) {
	return "���Ǹո��㿴����";
    }

    player->set("bingbu/ask_member", time());

    message_vision("$N��$n����һ���������ᡣ\n", me, player);

    tell_object(player, "���־�����\n");
    for (rank = 0; rank < 7; rank ++) {
	tell_object(player, "--------------- " + HELPER->rank_name(rank)+" --------------\n");
 	members = me->query("members/rank"+rank);
	num = 0;
	for (i=0; i<sizeof(members); i++) {
 	    if (members[i] != 0) {
		usr = get_player(members[i]);
		if (usr) {
		    if (rank > 4) {
			name = HELPER->player_title(player)+player->name();
		    } else {
			name = player->name();
		    }
		    tell_object(player, name);
		    num ++;
		    if (num % 5 == 0) {
			tell_object(player, "\n");
		    }else {
			tell_object(player, "\t");
		    }
	  	    if (usr->query_temp("temp_dummy"))
			destruct(usr);
		}
	    }
 	}
	if (num % 5 > 0) {
	    tell_object(player, "\n");
	}
    }
    return "����͸Ͻ��߰ɡ�";
}

string do_shengqian()
{
    object me = this_object();
    object player = this_player();
    int    rank, i;
    string *members;

    if (player->query("possessed")) return "�㱻�����ˡ�";
    if (! IS_SHIWEI(player)) {
	return "�㿪ʲô��Ц�������Ұ���ץ������";
    }
    rank = SHIWEI_LEVEL(player);
    if ( player->query("bingbu/job_cur") < HELPER->job_upgrade_num(rank)) {
	return "��ľ�����������ô������";
    }
    if (rank >= 6) 
	return "�������Ѿ���"+HELPER->player_title(player)+
	       "�ˣ������͡�����";

    if (! add_user_succ(me, player, rank+1)) {
	return "���˾���׿���������±�������Ϊ����û��ʵȱ��.";
    }

    // remove user from his current rank
    members = me->query("members/rank"+rank);
    for (i=0; i<sizeof(members); i++){
	if (members[i] == player->query("id")) {
	    members[i] = 0;
	}
    }
    me->set("members/rank"+rank, members);
    post_message(player->name()+"����"+HELPER->player_title(player)+"\n");
    me->save();

    return "�ã����˾���׿�����Ҿ�����Ϊ"+HELPER->player_title(player)+"�ɡ�";
}


string do_tuiyi()
{
    object me = this_object();
    object player = this_player();
    object yaopai;
    string *members, name=player->name(), id = player->query("id");
    int    i, slot, rank;

    if (player->query("possessed")) return "�㱻�����ˡ�";
    if (! IS_SHIWEI(player)) {
	return "�㿪ʲô��Ц�������Ұ���ץ������";
    }

    for (rank=0; rank<7; rank++){
	members = me->query("members/rank"+rank);
	if (!members) {
	    members = allocate(HELPER->rank_position_num(0));
	    for (i=0; i<sizeof(members); i++){
		members[i] = 0;
	    }
	    slot = -1;
	}else{
	    for (i=0; i<sizeof(members); i++){
		if (members[i] == id) slot = i;
		break;
	    }
	    if (i == sizeof(members)) slot=-1;
	    else {
		// we agree on which rank you are
		if (rank == player->query("family/generation")) {
		    break;
		}
	    }
	}
    }

    post_message(HELPER->player_title(player)+player->name()+"�����ˡ�\n");
    if (slot == -1) {
 	normalize(player);
	return "�ҵ�������û���㰡�������һ��ǰ����ע���˰ɡ�";
    }else {
	player->set("bingbu/leave_time", time());
	player->set("bingbu/leave_age", player->query("mud_age"));
        normalize(player);
 	members[slot] = 0;
	me->set("members/rank"+rank, members);
	me->save();
	return "�ðɣ���׼����ϻ���ɡ�";
    }
}


string do_toujun()
{
    object me = this_object();
    object player = this_player();
    object yaopai;
    int    leave_age;

    if (player->query("possessed")) return "�㱻�����ˣ��ҿɲ������㡣";
    if (IS_SHIWEI(player)) {
	return "�㿪ʲô��Ц�������Ұ����ְ��졣";
    }

    if ((player->query("family/family_name") == "ؤ��") &&
	(player->query("rank") > 1)) {
	return "����ؤ����֣����Ҫ�����ţ�";
    }

    if (player->query("gender") == "����") 
	return "�������ǻع�ȥ�ɡ�";

    if (player->query("gender") == "Ů��") 
	return "������㲻�ظ�����Ů�ӣ�Ҳ�������������٣�";
    
    if (player->query("combat_exp") < 20000) 
	return "�����书��΢�������Ϊ���ϳ�����";
    
    if (leave_age = player->query("bingbu/leave_age")) {
 	if (player->query("mud_age")-leave_age < HELPER->pending_time()) {
	    return "��ո��ϻ����������Ͷ����";
	}
    }

    // we allow this player to join, check positions available
    if (! add_user_succ(me, player, 0)) {
	return "�������־�û�п�ȱ�����һ���������ɡ�";
    }

    post_message(player->name()+"Ͷ����ʵ��"+HELPER->player_title(player)+"��\n");
    player->set("family", ([
	"family_name"    : "���־�",
	"enter_time"     : time(),
    ]));
    player->set("bingbu/job_total", 0);
    player->set("bingbu/job_rank0", 0);
    player->set("bingbu/job_rank1", 0);
    player->set("bingbu/job_rank2", 0);
    player->set("bingbu/job_rank3", 0);
    player->set("bingbu/job_rank4", 0);
    player->set("bingbu/job_rank5", 0);
    player->set("bingbu/job_rank6", 0);

    yaopai = new("/d/beijing/obj/yaopai.c");
    yaopai->move(player);
    player->set("suicong_num", 0);
    player->save();

    message_vision("$N��������ʦ�ţ��������־�����\n", player);
    message_vision("$N��$nһ���������ơ�����$n�ļ��˵������ϲ���Ϊ"
	+HELPER->rank_name(0)+"��\n", me, player);

    return "ȥ���ܹ��Ƕ�������ȥ�ɡ�";
}

/*
 * Demote a player if one of the following stands:
 * 1. if he died more than allowed times in his current position when rank<5
 * 2. if he died more than twice within two years mudtime when rank>=5
 * 3. if his job_lazy<4 and lazy_time over 1 week
 * 4. if his job_lazy<4 and lazy_mudtime over 12 hours
 *
 * return 0: nothing should be done.
 *        1: this player should be demoted.
 *        2: this player should be removed from the system.
 *
 * WIZ: IF YOU RECOVER A PLAYER, MAKE SURE ALL DATA ARE MANUALLY
 * RECOVERED FOR ALL LEVELS OF SHIWEI.  SOMETIMES IT IS NOT 
 * POSSIBLE. -chu
 */
string should_demote(object usr)
{
    int    *death_allowed = ({10, 5, 5, 3, 3, 2, 2});
    int    ret, rank, death, last_check;
    string msg;

    rank = SHIWEI_LEVEL(usr);
    death = usr->query("death_count");
    last_check = usr->query("bingbu/last_check");

    ret = 0;
    if (death - usr->query("bingbu/death_count") > death_allowed[rank]) {
	msg="��ְ�ڼ�������������";
	ret = 1;
    }

    // if 2 years have been past, reset
    if (rank >= 5) {
	if (usr->query("mud_age") - last_check > 518400) {
	    usr->set("bingbu/last_check", usr->query("mud_age"));
	    usr->set("bingbu/death_count", death);
	    usr->save();
	}
    }

    // check if he is doing jobs
    if (time() - usr->query("bingbu/job_lazy_time") >= 604800) {
	if (usr->query("bingbu/job_lazy") < 4) {
	    msg="���ڲ�����������";
	    ret = 1;
 	}
	usr->set("bingbu/job_lazy", 0);
	usr->set("bingbu/job_lazy_time", time());
    }
    if (usr->query("mud_age") - usr->query("bingbu/job_lazy_mudtime") >= 
	    43200) {
	if (usr->query("bingbu/job_lazy_mud") < 4) {
	    msg="���ڲ�������ֵ��";
	    ret = 1;
 	}
	usr->set("bingbu/job_lazy_mud", 0);
	usr->set("bingbu/job_lazy_mudtime", usr->query("mud_age"));
    }

    return 0;
}

void demote(object me, object usr, int old_rank)
{
    int i, j, position_found;
    string *members;

    for (i=old_rank-1; i>=0; i--){
	if (add_user_succ(me, usr, i)) {
	    tell_object(usr, "�㱻����"+HELPER->rank_name(i)+"\n");
	    post_message(usr->query("name")+"������"+
			HELPER->rank_name(i)+"\n");
 	    // remove suicong
	    if (usr->query("suicong_num") > HELPER->suicong_max(i)) {
		usr->set("suicong_num", HELPER->suicong_max(i));
	    }
	    return;
	}
    }
    normalize(usr);
    tell_object(usr, "�㱻�������ۡ�\n");
    post_message(usr->query("name")+"�㱻�������ۡ�\n");
}

void refresh_members()
{
    object me = this_object();
    int i, j, cloned_user;
    string *members, msg;
    object usr;

    for (i=0; i<7; i++){
	members = me->query("members/rank"+i);
        for (j=0; j<sizeof(members); j++){
	    if (! members[j]) continue;
	    usr = get_player(members[j]);

	    if (! usr) {
		members[j] = 0;	// expell
	    }else{
	 	if (! IS_SHIWEI(usr)) {
		    members[j] = 0;	// maybe he went to xx
		}else if ( msg=should_demote(usr)) {
		    members[j] = 0;
		    tell_object(usr, "������"+msg+"���㱻������ְ�ˡ�\n");
		    post_message(usr->name()+"����"+msg+"��������ְ�ˡ�\n");
		    demote(me, usr, i);
		    usr->save();
		}
 	    }
	    if (usr->query_temp("temp_dummy")) destruct(usr);
	}
	me->set("members/rank"+i, members);
    }
    me->save();
}
