#ifndef OUTPUTCONTROLLER_H
#define OUTPUTCONTROLLER_H

#include "baseio.h"

namespace duly_gui
{
	namespace controllers
	{
		class OutputController : public BaseIo
		{
		public:
            explicit OutputController(IoTypeRessouce::IoType type, QQuickItem *parent);

			/**
			* \brief Connect linkable together, create a link, and keep a reference on the visual curve
			* \param linkable
			* \param curve
			* \return Link *
			*/
			Link *connect(ALinkable *linkable, views::BezierCurve *curve) override;
		};
	}
}

#endif // OUTPUTCONTROLLER_H