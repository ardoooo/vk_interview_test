#include "view.hpp"

#include <fmt/format.h>

#include <userver/server/handlers/http_handler_base.hpp>

namespace service_template {

namespace {

class HandlerCounterGet final : public userver::server::handlers::HttpHandlerBase {
public:
  static constexpr std::string_view kName = "handler-counter-get";

  using HttpHandlerBase::HttpHandlerBase;

  mutable size_t counter{0};

  std::string HandleRequestThrow(
      const userver::server::http::HttpRequest &request,
      userver::server::request::RequestContext &) const override {
    return std::to_string(++counter);
  }
};

} // namespace


void AppendCounterGet(userver::components::ComponentList &component_list) {
  component_list.Append<HandlerCounterGet>();
}

} // namespace service_template
