// Room: /d/xiangyang/damen.c ����
// Modify By River 98/10
// Modify By Lklv 2001.9.21
// Modify by tangfeng for ���Ǿ�quest

inherit ROOM;
#include <ansi.h>
#include <wanted.h>

#define QUESTDIR "quest/���Ǿ�/"
#define QUESTDIR1 "quest/���Ǿ�/ѩ�ȼ���ƪ/"
#define QUESTDIR2 "quest/���Ǿ�/���̽��ƪ/"

void create()
{
	set("short", "��ݴ���");
	set("long", @LONG
������������ݵĴ��ţ����Ⱥ������ľ�������ҳ����ţ��ſڵ����Ϸ�
������һ��ڵ׽��ֵĴ��ң�����д���ĸ����֣���������ݡ�����ǰ��̨��
���Ը�����һ��ʯʨ���Ӵ��ſ���������ȥ����ݵ�Ժ��������������������
���󶼺�æµ�������Ա�վ��һ�������������������ϡ�
LONG
        );
	set("outdoors","���");
	set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"eroad1",
		"enter": "/d/wuguan/menlang",
	]));
	set("objects", ([
                "/d/wuguan/npc/menwei" : 1,
//                "/tmp/ciwei/menwei" : 1,
	]));
	set("incity",1);
	setup();
}

int valid_leave(object me,string dir)
{
	object *obj;
	int x;

	if ( me->query_temp( "wg_help" ) || me->query_temp( "wg_road" ) == 2 )
		return notify_fail("�������˵����" + RANK_D->query_respect(me) +
			"���������ĵ�һ��ɣ�˵�������Ͼ����������������\n");
	if ( me->query_temp( "wg_juanzeng" ) )
		me->delete_temp( "wg_juanzeng" );
	if ( me->query_temp( "wg_road" ) == 1 )
		me->delete_temp( "wg_road" );
	if ( dir == "enter" && !wizardp(me)) {
		if ( is_wanted(me) )
			return 0;
		if ( me->query("combat_exp") > 3000 )
		{
			if(!me->query(QUESTDIR1+"over") || me->query(QUESTDIR2+"over"))
				return notify_fail("������ǰ����һ�죺����书�����ˣ������ѧ����ʲô�ˡ�\n");
			if(me->query_temp(QUESTDIR2+"start"))
			{
				message_vision(HIY"\n�����ɻ�ؿ���$N����$N�ղ���ô��ȥ�ֳ����ˣ�\n", me);
				me->delete_temp("quest/busy");//
				me->delete_temp("quest/���Ǿ�");
				return notify_fail("������ǰ����һ�죺������ô�õ����飬����ݽ���������\n");
			}
			obj = users();
			x = sizeof(obj);
			while(x--)
			{
				if ( obj[x]->query_temp(QUESTDIR2+"start") && obj[x]!=me ) 
					return notify_fail("������ǰ����һ�죺"+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"�Ѿ�ȥ���̽��ȥ�ˣ����ٵȵȣ�");		  
			}
		}
	}
	if ( dir == "enter" && me->query(QUESTDIR1+"over")&& !me->query(QUESTDIR2+"over"))
	{
		message_vision(HIY"\n$N��ͷ�ƺ�������˵��Щʲô����������һ�����˳�����\n", me);
		if(me->query(QUESTDIR+"time")&&time()-me->query(QUESTDIR+"time")<86400)
			return notify_fail("������ǰ����һ�죺���������������æ�ˣ�"+RANK_D->query_respect(me) +"������Ϣȥ�ɣ�");		  
		if(me->query(QUESTDIR+"combat_exp")&&me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<500000)
			return notify_fail("������ǰ����һ�죺��"+RANK_D->query_respect(me) +"Ŀǰ�ľ�������ȥ��Ҳ������ʲô������ץ�������ɣ�");

		message_vision(HIY"��������һ������������\n", me);
		message_vision(HIY"ֻ���������Ա�һ����$N���ŷ��Ｗ�˽�ȥ��\n", me);
		me->set(QUESTDIR+"time",time());
		me->set(QUESTDIR+"combat_exp",me->query("combat_exp")); 
		me->set(QUESTDIR2+"start",1);//��ʼ
		me->set_temp(QUESTDIR2+"start",1);
		me->set_temp("quest/busy",1);
	}
	return ::valid_leave(me, dir);
}
