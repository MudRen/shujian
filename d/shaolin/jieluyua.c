//jieluyuan.c

inherit ROOM;
#include <ansi.h>
#include <login.h>
void create()
{
	set("short", HIB"����Ժ"NOR);
	set("long", @LONG
��������Ż����գ��ܲ�͸�硣�������ڰ��磬Ҳ�����ҹһ�㣬ÿ����
����ǽ�ϣ���ȼ�ż�֦ţ�;��򡣵��Ϲ����Ž�ħΤ���·�����һ����ˮţƤ
�ޡ�������弰��������ִ�����ȡ�����վ���˻����䵶��ִ��ɮ����������
�����ϵ�����������㣬���㲻���������⡣
LONG
	);

	set("exits", ([
		"west" : __DIR__ "songshu4",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/xuan-ji" : 1,
		__DIR__"npc/zjseng" : 1,
                __DIR__"npc/slseng" : 1,
		__DIR__"npc/xiao-tong" : 1
	]));
        
	set("no_fight", "1");
	set("valid_startroom",1);

	setup();
}

void init()
{	
	object ob;

	if (interactive(ob = this_player())) {
		if (wizardp(ob)) return;
		if (!ob->query("guilty") && ob->query("family/family_name") == "������") return;
		message_vision(HIY "$Nһ������Ժ��...ֻ��������ȣ���ͬը�װ��ڴ������졣"
		"$N��������������Ҳվ����ס����һ����ͨһ������������\n\n" NOR, ob);

		ob->set("startroom", "/d/shaolin/jieluyua");

		if (!ob->query_condition("killer"))
			call_out("processing", 3, ob);
	}
}

void processing(object ob)
{
	if (!ob) return;
	tell_object(ob, HIW "\n�㶨�˶���̧ͷϸ����ֻ����ʮ���ֵ�ɮ�˽�������Χ������\n"
		"һƬѩ���ĵ���Ƶ����۶�����������ǰ���ĸ�̨�Ϸ���һ��\n"
		"̫ʦ�Σ����и�����λ�����ü����ɮ����ɫ���࣬Ŀ�侫�⣬\n"
		"�ݺݵص����㡣\n\n\n" NOR);

	if (ob->query("family/family_name") != "������"){
		message_vision(HIY "����һ����ȣ����ȴ󵨿�ͽ���ô����£����ڲ��죬�õ����"
		"���������£������������С��˺�����Ϊ��ִ��ɮ�����ڣ�\n\n" NOR, ob);
		call_out("responsing", 3, ob, 3);
		return;
	}
	if (ob->query("guilty") == 1)
		message_vision(HIY "����һ����ȣ�"+ob->query("name")+"�������½������գ�ȴ����ɱ��Խ����������Ϊ��"
		"�۷���䣬�ܻ�����ǧ�������� ��õ������ִ��ɮ�����ڣ�\n\n" NOR, ob);

	if (ob->query("guilty") == 3)
		message_vision(HIY "����һ����ȣ�"+ob->query("name")+"�����»����������������������˵������룬"
		"���ô��˵أ����ڲ��죬�õ����ִ��ɮ�����ڣ�\n\n" NOR, ob); 

	if (ob->query("guilty") == 2){
		message_vision(HIY "���Ŷ���$N���˰��ã�˵����"+ob->query("name")+"����Ͷ����ƣ��������������ñ��ã�\n"
		"���������׽�ɱ�������˺�����������ɮ�ҵ���� "
		"��ȥ�գ��´ζ������ģ�\n\n" NOR, ob);
		ob->delete("guilty");
		return;
	}
	call_out("responsing1", 3, ob, 3);
}

void responsing(object ob, int i)
{
	int j;

	if (!ob) return;
	message_vision(HIR "ɮ������Ӧ���������ڣ�\n" NOR, ob);

	i--;
	j = random(3);

	if (i == 0) {	
		call_out("beating", 3, ob);
		return;
	}

	call_out("responsing", j, ob, i);
}

void responsing1(object ob, int i)
{
	int j;

	if (!ob) return;
	message_vision(HIR "ɮ������Ӧ���������ڣ�\n" NOR, ob);

	i--;
	j = random(3);

	if (i == 0) {
		call_out("beating1", 3, ob);
		return;
	}

	call_out("responsing1", j, ob, i);
}

void beating(object ob)
{

	if (!ob) return;
	message_vision(HIY "\n\n���źȵ����������٣���"+ob->query("name")+"����ɮ���Ѻ���£���ϴ�Ļڸģ�"
	"�����ͷţ���ͼԽ�������һ�ȣ�\n\n" NOR, ob);

	message_vision(HIR "ɮ����һӿ���ϣ��Ұ����£�$Nʹ�û��˹�ȥ......\n" NOR, ob);

	ob->delete("guilty");
	
	ob->move(__DIR__"jianyu");
	ob->unconcious();
}

void beating1(object ob)
{
	int i;

	if (!ob) return;
	i = 20 + ob->query("combat_exp") / 100000 * 10;
	if (i > 50) i = 50;

	ob->set("carry_count", i);
	message_vision(HIY "\n\n���źȵ����������٣���"+ob->query("name")+"��ȥ�����ˮ"
		+ chinese_number(i) + "Ͱ����ϴ�Ļڸģ�"
	"�����ͷţ���ͼ͵�������һ�ȣ�\n\n" NOR, ob);

	message_vision(HIR "ɮ����һӿ���ϣ��Ұ����£�$Nʹ�û��˹�ȥ......\n" NOR, ob);

	ob->delete("guilty");
	
	new(__DIR__"obj/liao_kao")->move(ob);
        ob->unconcious();
	ob->move(__DIR__"houdian");
	ob->set("startroom", "/d/shaolin/houyuan");
}

int valid_leave(object me, string dir)
{
	mapping fam;

        if (userp(me) && dir == "west" && !wizardp(me)) {
		if (mapp(fam = me->query("family"))
		&& fam["family_name"] == "������" 
		&& !me->query("guilty")) ;
		else
			return notify_fail("����˵��: �󵨣��㻹�����ܣ�ִ��ɮ�����ڣ�\n");
	}
	return ::valid_leave(me, dir);
}
