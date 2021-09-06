// Update by lsxk@hsbbs  ����ͨ����Ʒ��߽�9jian�ļ��ʡ�

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
��������Ů���ɽ��һ��Сɽ�ȣ������˼����������й������죬����ɭ
ɭ��ż����Զ�����������������������������㣬��ֱ���������Լ���
��������Դ��
������ԶԶ�Ŀ�������������С�ݣ����������Ѿ��þ�ûס�����ˡ������ﲻ
���������������ô���أ������뿪�Ļ�����(leave)�ɡ�
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"midong",
                 "leave"  :   __DIR__"siguoya",

	]));

	set("outdoors", "��ɽ" );

	setup();
}

void init()
{
	add_action("do_shout","han");
}

int do_shout(string arg)
{
	object ob,me;
   int i, j, times;
	me = this_player();

	if (!me->query_temp("mb")) return 0;

	if ( !arg || arg!= "����ǰ��")
	{
		write("����Ϲ���ҽ�Щʲô?\n");
		return 1;
	}

	if (me->is_busy())
	{
		write("����æ���أ����ܺ��С�\n");
		return 1;
	}

	if (me->is_fighting())
	{
		write("�㻹��ר�Ĵ�ܰɡ�\n");
		return 1;
	}

	times = (time() - me->query_temp("mb"))/60;

	message_vision(HIY"\n$N���õ���֮����������Х��:������ǰ����������\n"NOR,me);

        if (!wizardp(me) && times > 9000) {
		me->delete_temp("han");
		me->delete_temp("mb");
		log_file("quest/jiujian",sprintf("%8s%-10s�ں�ɽ��ʱ��̫�ã�δ�����κ����������%d���Σ�%d��\n",
			me->name(1), "("+capitalize(me->query("id"))+")", me->query("kar"), me->query("mianbi")),me);
		me->move(__DIR__"siguoya");
		tell_object(me, "�������Ȼ��Ȥ���ֻص���˼���¡�\n");
		tell_room(environment(me), me->name() + "�Ӻ�ɽ���˹�����\n", ({ me }));
		return 1;
	}

	if ( me->query_temp("han") > 2 ) 
	{
		me->delete_temp("han");
		me->delete_temp("mb");
		log_file("quest/jiujian",sprintf("%8s%-10s�ں�ɽδ�����κ����������%d���Σ�%d��\n",
			me->name(1), "("+capitalize(me->query("id"))+")", me->query("kar"), me->query("mianbi")),me);
		me->move(__DIR__"siguoya");
		tell_object(me, "�������Ȼ��Ȥ���ֻص���˼���¡�\n");
		tell_room(environment(me), me->name() + "�Ӻ�ɽ���˹�����\n", ({ me }));
		return 1;
	}

// by lsxk@hsbbs  ����ͨ����Ʒ��߽�9jian�ļ��ʡ�
   if(me->query_temp("sj_credit/quest/hs/jiujian")){
       me->delete_temp("sj_credit/quest/hs/jiujian");
       i = 18;
   }
   else i = 22;

	// Modified by mxzhao 2004/05/01 for �����Ѷ�
   if( random(me->query("kar")) < i )
	{
	// End
		me->add_temp("han", 1);
		me->add_busy(1);
		tell_object(me, "��Ұ�ž�������Ψ�пչȻ������Ʈɢ��\n");
		return 1;
	}
	log_file("quest/jiujian",sprintf("%s(%s)�ں�ɽ�����ﲮ�⣬����%d���Σ�%d��\n",
		me->name(1), capitalize(me->query("id")), me->query("kar"), me->query("mianbi")));

	me->delete_temp("han");
	me->delete_temp("mb");

	ob=new(__DIR__"npc/tbg");
	ob->move(this_object());
	j = (int)me->query("max_pot") - 80;

	ob->set_skill("blade",j);
	ob->set_skill("parry",j);
	ob->set_skill("cuff",j);
	ob->set_skill("dodge",j);
	ob->set_skill("shandian-daofa",j);
	ob->set_skill("taizu-quan",j);
	ob->set_skill("force",j);
	ob->set_skill("huntian-qigong",j);
	ob->set_skill("shaolin-shenfa",j);

	ob->map_skill("dodge","shaolin-shenfa");
	ob->map_skill("blade","shandian-daofa");
	ob->map_skill("cuff","taizu-quan");
	ob->map_skill("parry","shandian-daofa");
	ob->map_skill("force","huntian-qigong");
	ob->prepare_skill("cuff","taizu-quan");

	ob->set("combat_exp",(int)me->query("combat_exp")*2);
	ob->set("max_qi", me->query("max_qi")*3/2);
	ob->set("max_neili",me->query("max_neili")*3/2);
	ob->set("neili",(int)me->query("max_neili")*2 - 1); 
	ob->set("eff_jingli", me->query("max_neili")*2/3);
	message_vision("һ����Ӱ��ɽ������,����������Ѿ���$N�����ڿ��쵶����֮�¡�\n",me);
	ob->kill_ob(me);
	remove_call_out("confirm");
	call_out("confirm", 20, me);
	return 1;
}

int confirm(object me)
{
        int i,j=0;
	object ob, *ppl;
ppl=users();
i=sizeof(ppl);

while(i--){
if( userp(ppl[i])&& !wizardp(ppl[i])&&!ppl[i]->query("no_pk")&& ppl[i]->query("fengset"))
        j++;
          }
//����9j��ϴ��id��������Ϊ3��

	ob=present("tian boguang",this_object());
	message_vision(CYN"һ����ӰƮȻ���䣬������������Ҫָ��$N���У��ѵ���ʰ����$n�������?\n"NOR, me,ob);
	message_vision(CYN"$N��ʹһ�С��׺���ա������ű�ʹ���з����ǡ�����ʹһ�С������ա���\n"
			+"������ʹ���ؽ�ʽ��������һ�������ϲ�����ʹ����ʮ����ʽ��\n"NOR,me);
	message_vision(CYN"$n�мܲ�ס��������ɽ����ȥ����������̾һ����ʧ��ɽ��\n"NOR,me,ob);

        if (!me->query("fengset") && j<=8){

		me->add("combat_exp",15000);
		me->set("fengset",1);
	        me->set_temp("met_feng",1);
		write(HIW"��õ��������ָ�㣬�ٸй��������\n"NOR);
                log_file("quest/jiujian",sprintf(HIR"%s(%s)�ڴ����ﲮ��󣬵õ��������ָ�㣬�Σ�%d������������%d���ɹ���\n"NOR,
			me->name(1), capitalize(me->query("id")), me->query("mianbi"),j));	
	destruct(ob);
return 1;

	}

         else {	message_vision(CYN"$n�мܲ�ס��������ɽ����ȥ����������̾һ����ʧ��ɽ��\n"NOR,me,ob);
                message_vision(CYN"$N������һ��㱣�ȴ��������������Զȥ��\n"NOR,me);
               log_file("quest/jiujian",sprintf("%s(%s)�ڴ����ﲮ��󣬵õ��������ָ�㣬�Σ�%d������������%d���������������࣬ʧ�ܡ�\n",
			me->name(1), capitalize(me->query("id")), me->query("mianbi"),j));
if(living(me))  me->move(__DIR__"siguoya");
	destruct(ob);
              return 1;
        }

	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") == "��ɽ��"
	 && me->query("fengset") 
	 && dir == "northdown") {
		me->move(__DIR__"siguoya");
		me->delete_temp("mark/steps");
		return notify_fail("��ѭ�ŷ�������ߵĽݾ�һ���Ӿ�������˼���¡�\n");
	}
	return ::valid_leave(me, dir);
}
